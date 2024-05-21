#include <iostream>
#include <vector>
#include "Login.cpp"
#include "Project.cpp"
#include "Task.cpp"

using namespace std;

int main(){
    int option;
    int terminator = 0;
    Login login1;

    // para la creacion de proyectos tendremos un iterador que nos permitira crear varios proyectos
    int projectAmount;
    int taskAmount;
    vector<Project> variousProjects;
    vector<Task> variousTasks;

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
        }else if(option == 2){
            if(login1.loginAttempt()){
                while(terminator == 0){
                    cout << "1. Crear proyecto" << endl;
                    cout << "2. Ver proyectos" << endl;
                    cout << "3. Tareas" << endl;
                    cout << "4. Salir" << endl;
                    cin >> option;
                    if(option == 1){
                            Project project1;
                            project1.createProject();
                            variousProjects.push_back(project1);
                    }else if(option == 2){
                        cout << "Proyectos: " << endl;
                        for(int i = 0; i < variousProjects.size(); i++){
                            cout << "Proyecto: " << i+1;
                            cout << variousProjects[i].getName() << endl;
                            cout << endl;
                            }
                    }else if(option == 3){
                        cout << "Bienvenido al apartado de tareas! Que desea hacer?" << endl;
                        cout << "1. Crear tarea" << endl;
                        cout << "2. Ver tareas" << endl;
                        cout << "3. Modificar tarea" << endl;
                        cout << "4. Salir" << endl;
                        cin >> option;

                        if(option == 1){
                            Task task1;
                            task1.createTask();
                            variousTasks.push_back(task1);
                        }else if(option == 2){
                            cout << "Tareas: " << endl;
                            for(int i = 0; i < variousTasks.size(); i++){
                                cout << "Tarea: " << i+1;
                                cout << variousTasks[i].getName() << endl;
                                cout << "Estado: " << variousTasks[i].getStatus() << endl;
                                cout << endl;
                            }
                        }else if(option == 3){
                            cout << "Que tarea desea modificar?" << endl;
                            for(int i = 0; i < variousTasks.size(); i++){
                                cout << "Tarea: " << i+1;
                                cout << variousTasks[i].getName() << endl;
                            }
                            int taskOption;
                            cin >> taskOption;
                            cout << "Que desea modificar?" << endl;
                            cout << "1. Nombre" << endl;
                            cout << "2. Estado" << endl;
                            cout << "3. Fecha limite" << endl;
                            cout << "4. Comentarios" << endl;
                            cout << "5. Prioridad" << endl;
                            int taskOption2;
                            cin >> taskOption2;
                            if(taskOption2 == 1){
                                string name;
                                cout << "Nuevo nombre: ";
                                cin >> name;
                                variousTasks[taskOption-1].setName(name);
                            }else if(taskOption2 == 2){
                                string status;
                                cout << "Nuevo estado: ";
                                cin >> status;
                            }
                        }
                    }else if(option == 4){
                        terminator = 1;
                    }else{
                        cout << "Opcion no valida" << endl;
                    }
                }
            }
        }else if(option == 3){
            cout << "Salir" << endl;
            terminator = 1;
        }
        else{
            cout << "Opcion no valida" << endl;
        }
    }
}
