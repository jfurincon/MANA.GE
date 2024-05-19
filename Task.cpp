#include <iostream>
#include <vector>

using namespace std;

class Task{
    private:
        string name;
        string status;
        vector<string> variousResponsibles;
        string deadline;
        string comments;
        string priority;
    public:
    // Constructor vacio
    Task(){

    }
    // getters y setters
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }

    void setStatus(string status){
        this->status = status;
    }
    string getStatus(){
        return this->status;
    }

    void setDeadline(string deadline){
        this->deadline = deadline;
    }
    string getDeadline(){
        return this->deadline;
    }

    void setComments(string comments){
        this->comments = comments;
    }
    string getComments(){
        return this->comments;
    }

    void setPriority(string priority){
        this->priority = priority;
    }
    string getPriority(){
        return this->priority;
    }

    // Metodos
    void createTask(){
        string name;
        string status;
        string responsible;
        string deadline;
        string comments;
        string priority;

        cout << "Nombre de la tarea: ";
        cin >> name;
        setName(name);

        cout << "Estado de la tarea: seleccione una opcion";
        cout << "1. Pendiente";
        cout << "2. En progreso";
        cout << "3. Terminada";
        int option;
        cin >> option;
        switch(option){
            case 1:
                status = "Pendiente";
                break;
            case 2:
                status = "En progreso";
                break;
            case 3:
                status = "Terminado";
                break;
            default:
                status = "Pendiente";
                break;
        }
        setStatus(status);

        cout << "Cuantas personas son responsables de la tarea?";
        int amount;
        cin >> amount;
        for(int i = 0; i < amount; i++){
            cout << "Digite el nombre del Responsable " << i+1 << ": ";
            cin >> responsible;
            variousResponsibles.push_back(responsible);
        }

        cout << "Fecha limite de la tarea, utiliza el formato dd/mm/yyyy sin espacios y sin slash: ";
        cin >> deadline;
        setDeadline(deadline);

        cout << "Comentarios de la tarea: ";
        cin >> comments;
        setComments(comments);

        cout << "Prioridad de la tarea, seleccione una opcion:";
            cout << "1. Baja";
            cout << "2. Media";
            cout << "3. Alta";
            int option;
            cin >> option;
            switch(option){
                case 1:
                    priority = "Baja";
                    break;
                case 2:
                    priority = "Media";
                    break;
                case 3:
                    priority = "Alta";
                    break;
                default:
                    priority = "Baja";
                    break;
            }
        setPriority(priority);
    };

    void changeStatus(){
        string status;
        cout << "El estado actual de la tarea es: " << getStatus() << endl;
        cout << "Desea cambiarla a:";
        cout << "1. Pendiente";
        cout << "2. En progreso";
        cout << "3. Terminada";
        int option;
        cin >> option;
        switch(option){
            case 1:
                status = "Pendiente";
                break;
            case 2:
                status = "En progreso";
                break;
            case 3:
                status = "Terminado";
                break;
            default:
                status = "Pendiente";
                break;
        }
        setStatus(status);
        cout << "El estado de la tarea ha sido cambiado a: " << getStatus() << endl;
    };


}