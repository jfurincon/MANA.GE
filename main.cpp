#include <iostream>
#include <vector>
#include "Login.cpp"
#include "Project.cpp"
#include "Task.cpp"
#include "Notes.cpp"
#include <map>
#include <fstream>

using namespace std;

void orderProjectsbyName(vector<Project> &projects){
    for(int i = 0; i < projects.size(); i++){
        for(int j = 0; j < projects.size(); j++){
            if(projects[i].getName() < projects[j].getName()){
                Project temp = projects[i];
                projects[i] = projects[j];
                projects[j] = temp;
            }
        }
    }
};

void orderProjectbyDate(vector<Project> &projects){
    for(int i = 0; i < projects.size(); i++){
        for(int j = 0; j < projects.size(); j++){
            if(projects[i].getDeadline() < projects[j].getDeadline()){
                Project temp = projects[i];
                projects[i] = projects[j];
                projects[j] = temp;
            }
        }
    }
};

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

// funcion para relacionar un proyecto con una tarea mediane un mapa
void relationTask(map<Project, vector<Task>>& map, vector<Task>& variousTasks2, const vector<Project> variousProjects, int index){
    map[variousProjects[index-1]] = variousTasks2;
};

// funcion para relacionar una nota con una tarea
void relationNoteProj(map<Project, vector<Note>>& map, vector<Note>& variousNotes2, const vector<Project> variousProjects, int index){
    map[variousProjects[index-1]] = variousNotes2;
};


int main(){

    // se crea un archivo para guardar los datos, incluyendo datos de la persona que se registra como todo lo referente a proyectos, tareas y notas.
    string filename = "data.txt";
    ofstream outfile(filename);

    int option;
    int terminator = 0;
    Login login1;

    vector<Project> variousProjects;
    vector<Task> variousTasks; // para la lista de tareas inicial
    vector<Task> variousTasks2; // para la lista de tareas relacionadas a un proyecto
    vector<Note> variousNotes;
    vector<Note> variousNotes2; // para la lista de notas relacionadas a una tarea

    map<Project, vector<Task>> task_map;
    map<Project, vector<Note>> noteP_map;

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
            // se guardan los datos en el archivo
            outfile << "username: " << login1.getUsername() << endl;
            outfile << "nombre " << login1.getName() << endl;
            outfile << "e-mail: " << login1.getEmail() << endl;
            outfile << "cel: " << login1.getPhone() << endl;
            outfile << endl;
        }else if(option == 2){
            if(login1.loginAttempt()){
                while(terminator == 0){
                    cout << "1. Crear proyecto" << endl;
                    cout << "2. Ver proyectos" << endl;
                    cout << "3. Tareas" << endl;
                    cout << "4. Notas" << endl;
                    cout << "5. Exportar datos" << endl;
                    cout << "6. Salir" << endl;
                    cin >> option;
                    if(option == 1){
                            Project project1;
                            project1.createProject();
                            // se guardan los datos en el archivo
                            outfile << "Proyecto: " << endl;
                            outfile << project1.getName() << endl;
                            outfile << project1.getStatus() << endl;
                            outfile << project1.getDeadline() << endl;
                            outfile << endl;

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

                            cout << "Notas relacionadas: " << endl;
                            // se imprime el mapa de notas relacionadas a un proyecto
                            for(int j = 0; j < noteP_map[variousProjects[i]].size(); j++){
                                cout << "Nota " << j+1 << ":";
                                cout << noteP_map[variousProjects[i]][j].getTitle() << endl;
                            }
                            cout << endl;
                        }

                        cout << "1. Ordenar proyectos por nombre" << endl;
                        cout << "2. Ordenar proyectos por fecha limite" << endl;

                        int orderOption;
                        cin >> orderOption;

                        if(orderOption == 1){
                            orderProjectsbyName(variousProjects);
                        }else if(orderOption == 2){
                            orderProjectbyDate(variousProjects);
                        }
                        // se imprime nuevamente el vector de proyectos ya ordenado
                        for(int i = 0; i < variousProjects.size(); i++){
                            cout << "Proyecto " << i+1 << ":";
                            cout << variousProjects[i].getName() << endl;
                            cout << "Tareas relacionadas: " << endl;
                            for(int j = 0; j < task_map[variousProjects[i]].size(); j++){
                                cout << "Tarea " << j+1 << ":";
                                cout << task_map[variousProjects[i]][j].getName() << endl;
                            }
                            cout << "Notas relacionadas: " << endl;
                            for(int j = 0; j < noteP_map[variousProjects[i]].size(); j++){
                                cout << "Nota " << j+1 << ":";
                                cout << noteP_map[variousProjects[i]][j].getTitle() << endl;
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
                            // se guardan los datos en el archivo
                            outfile << "Tarea: " << endl;
                            outfile << task1.getName() << endl;
                            outfile << task1.getStatus() << endl;
                            outfile << task1.getPriority() << endl;
                            outfile << task1.getDeadline() << endl;

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
                                // inicialmente se inserta la tarea en un nuevo vector por si se quieren agregar 1+ tareas a un proyecto
                                variousNotes2.push_back(note1);
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
                                        cout << "Desea relacionar OTRA nota con este proyecto?" << endl;
                                        cout << "1. Si" << endl;
                                        cout << "2. No" << endl;

                                        cin >> option;

                                        if(option == 1){
                                            Note note2;
                                            note2.createNote();
                                            variousNotes.push_back(note2);
                                            variousNotes2.push_back(note2);
                                        }
                                    }
                                    // se relaciona el proyecto con la tarea
                                    relationNoteProj(noteP_map, variousNotes2, variousProjects, projectOption);
                                }   
                            }else if(option == 2){
                                // simplemente registrar el proyecto a su respectivo vector
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
                        // exportar datos
                        outfile.close();
                        cout << "Datos exportados exitosamente" << endl;
                    }else if(option == 6){
                        terminator = 1;
                    }else{
                        cout << "Opcion no valida" << endl;
                    }
                }
            }
        }
        else if(option == 3){
            cout << "Salir" << endl;
            terminator = 1;
        }else{
            cout << "Opcion no valida" << endl;
        }
    }
}
