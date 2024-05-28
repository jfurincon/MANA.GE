#include <iostream>
#include <vector>
#include "Login.cpp"
#include "Project.cpp"
#include "Task.cpp"
#include "Notes.cpp"
#include <map>

using namespace std;

void orderTaskPriority(vector<Task> &tasks){
    for(int i = 0; i < tasks.size(); i++){
        for(int j = 0; j < tasks.size(); j++){
            if(tasks[i].getPriority() < tasks[j].getPriority()){
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
};

void orderTaskResponsible(vector<Task> &tasks){
    for(int i = 0; i < tasks.size(); i++){
        // en esta funcion se ordenaran las tareas por responsables
        tasks[i].orderResponsibles();  
    }
};

void relationTask(map<Project, vector<Task>>& map, vector<Task>& variousTasks2, const vector<Project> variousProjects, int index){
    map[variousProjects[index-1]] = variousTasks2;
};

int main(){
    int option;
    int terminator = 0;
    Login login1;

    vector<Project> variousProjects;
    vector<Task> variousTasks; // para la lista de tareas inicial
    vector<Task> variousTasks2; // para la lista de tareas relacionadas a un proyecto
    vector<Note> variousNotes;

    map<Project, vector<Task>> task_map;

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
                    cout << "4. Notas" << endl;
                    cout << "5. Salir" << endl;
                    cin >> option;
                    if(option == 1){
                            Project project1;
                            project1.createProject();
                            variousProjects.push_back(project1);
                    }else if(option == 2){
                        cout << "Proyectos: " << endl;
                        for(int i = 0; i < variousProjects.size(); i++){
                            cout << "Proyecto " << i+1 << ":";
                            cout << variousProjects[i].getName() << endl;
                            cout << "Tareas relacionadas: " << endl;

                            // se imprime el mapa de tareas relacionadas a un proyecto
                            for(int j = 0; j < task_map[variousProjects[i]].size(); j++){
                                cout << "Tarea " << j+1 << ":";
                                cout << task_map[variousProjects[i]][j].getName() << endl;
                            }
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
                            // aqui preguntamos si desea relacionar la tarea con algun proyecto
                            cout << "Desea relacionar la tarea con algun proyecto?" << endl;
                            cout << "1. Si" << endl;
                            cout << "2. No" << endl;
                            int option;
                            cin >> option;

                            if(option == 1){
                                // inicialmente se inserta la tarea en un nuevo vector por si se quieren agregar 1+ tareas a un proyecto
                                variousTasks2.push_back(task1);
                                // relacionar proyecto con tarea mediante un mapa, se muestran los proyectos a elegir
                                cout << "Proyectos: " << endl;
                                for(int i = 0; i < variousProjects.size(); i++){
                                    cout << "Proyecto " << i+1 << endl;
                                    cout << variousProjects[i].getName() << endl;
                                    cout << endl;
                                }
                                if(variousProjects.size() == 0){
                                    cout << "No hay proyectos disponibles" << endl;
                                }else{
                                    cout << "A que proyecto desea relacionar la tarea?" << endl;
                                    int projectOption;
                                    cin >> projectOption;
                                    option = 1;

                                    while(option != 2){
                                        cout << "Desea relacionar OTRA tarea con este proyecto?" << endl;
                                        cout << "1. Si" << endl;
                                        cout << "2. No" << endl;

                                        cin >> option;

                                        if(option == 1){
                                            Task task2;
                                            task2.createTask();
                                            variousTasks.push_back(task2);
                                            variousTasks2.push_back(task2);
                                            /*
                                            PRUEBA PARA IMPRESION DEL VECTOR DE TAREAS2
                                            for(int i = 0; i < variousTasks2.size(); i++){
                                                cout << "Tarea " << i+1 << ":" << endl;
                                                cout << variousTasks2[i].getName() << endl;
                                                cout << endl;
                                            }
                                            */
                                        }
                                    }
                                    // se relaciona el proyecto con la tarea
                                    relationTask(task_map, variousTasks2, variousProjects, projectOption);
                                }   
                            }else if(option == 2){
                                // simplemente registrar el proyecto a su respectivo vector
                            }
                        }else if(option == 2){
                            cout << "Tareas: " << endl;
                            for(int i = 0; i < variousTasks.size(); i++){
                                cout << "Tarea " << i+1 << ":" << endl;
                                cout << variousTasks[i].getName() << endl;
                                cout << "Estado: " << variousTasks[i].getStatus() << endl;
                                cout << "Prioridad: " << variousTasks[i].getPriority() << endl;
                                cout << "Responsables: " << endl;
                                for(int j = 0; j < variousTasks[i].getResponsibles().size(); j++){
                                    cout << variousTasks[i].getResponsibles()[j] << endl;
                                }
                                cout << endl;
                            }
                            // en este apartado iniciamos la opcion para ordenar las tareas por prioridad
                            cout << "1. Ordenar tareas por Prioridad" << endl;
                            cout << "2. Ordenar responsables de las tareas por nombre" << endl;
                            int orderOption;
                            cin >> orderOption;
                            if(orderOption == 1){
                                orderTaskPriority(variousTasks);
                            }else if(orderOption == 2){
                                // ordenar por responsables
                                orderTaskResponsible(variousTasks);
                            }
                            for(int i = 0; i < variousTasks.size(); i++){
                                cout << "Tarea: " << i+1;
                                cout << variousTasks[i].getName() << endl;
                                cout << "Estado: " << variousTasks[i].getStatus() << endl;
                                cout << "Prioridad: " << variousTasks[i].getPriority() << endl;
                                cout << "Responsables: " << endl;
                                for(int j = 0; j < variousTasks[i].getResponsibles().size(); j++){
                                    cout << variousTasks[i].getResponsibles()[j] << endl;
                                }
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
                        }else if(option == 4){
                            // break al menu principal
                        }
                    }else if(option == 4){
                        // apartado de notas
                        cout << "Bienvenido al apartado de notas! Que desea hacer?" << endl;
                        cout << "1. Crear nota" << endl;
                        cout << "2. Ver notas" << endl;
                        cout << "3. Salir" << endl;
                        cin >> option;

                        if(option == 1){
                            Note note1;
                            note1.createNote();
                            variousNotes.push_back(note1);
                            cout << "Desea relacionar la nota con alguna tarea o proyecto?" << endl;
                            cout << "1. Si" << endl;
                            cout << "2. No" << endl;
                            int option;
                            cin >> option;

                            if(option == 1){
                                // relacionar nota con tarea o proyecto
                            }else if(option ==2){
                                // simplemente registrar la nota a su respectivo vector
                            }
                        }else if(option == 2){// se muestran las notas. NOTA: HAY QUE HACER VER A QUE PROYECTO O TAREA PERTENECE
                            for(int i = 0; i < variousNotes.size(); i++){
                                cout << "Nota: " << i+1;
                                cout << variousNotes[i].getTitle() << endl;
                                cout << "Contenido: " << variousNotes[i].getContent() << endl;
                                cout << "Autor: " << variousNotes[i].getAuthor() << endl;
                                cout << "Reaccion: " << variousNotes[i].getReaction() << endl;
                                cout << endl;
                            }
                        }else if(option == 3){
                            // break al menu principal
                        }

                    }else if(option == 5){
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
