#include <iostream>
#include <vector>
#include "Login.cpp"
#include "Project.cpp"

using namespace std;

int main(){
    int option;
    int terminator = 0;
    Login login1;

    // para la creacion de proyectos tendremos un iterador que nos permitira crear varios proyectos
    int projectAmount;
    vector<Project> variousProjects;

    cout << "MANA.ge" << endl;
    cout << "Bienvenido a la plataforma #1 de gestion de proyectos \n" << endl;
    cout << "Por favor, registrese o inicie sesion para continuar \n" << endl;

    while(terminator == 0){

        cout << "1. Registrarse" << endl;
        cout << "2. Iniciar sesion" << endl;
        cout << "3. Salir" << endl;

        cin >> option;

        if(option == 1){
            login1.registerUser();
        }
        else if(option == 2){
            if(login1.loginAttempt()){
                while(terminator == 0){
                    cout << "1. Crear proyecto" << endl;
                    cout << "2. Ver proyectos" << endl;
                    cout << "3. Salir" << endl;
                    cin >> option;
                    if(option == 1){
                        cout << "Cuantos proyectos desea crear?" << endl;
                        cin >> projectAmount;
                        for(int i = 0; i < projectAmount; i++){
                            Project project1;
                            project1.createProject();
                            variousProjects.push_back(project1);
                        }
                    }
                    else if(option == 2){
                        for(int i = 0; i < variousProjects.size(); i++){
                            cout << "Proyecto " << i+1 << endl;
                            cout << "Nombre: " << variousProjects[i].getName() << endl;
                            cout << "Propietario: " << variousProjects[i].getPropietary() << endl;
                            cout << "Descripcion: " << variousProjects[i].getDescription() << endl;
                            cout << "Estado: " << variousProjects[i].getStatus() << endl;
                            cout << "Fecha limite: " << variousProjects[i].getDeadline() << endl;
                        }
                    }
                    else if(option == 3){
                        cout << "Salir" << endl;
                        terminator = 1;
                    }
                    else{
                        cout << "Opcion no valida" << endl;
                    }
                }
            }
        }
        else if(option == 3){
            cout << "Salir" << endl;
            terminator = 1;
        }
        else{
            cout << "Opcion no valida" << endl;
        }
    }
}
