#include <iostream>

using namespace std;

class Project{
    private:
        string name;
        string propietary;
        string description;
        string status;
        string deadline; // la fecha debe ser un input dd/mm/yyyy
        // para poder convertir el string a un formato de fecha y tener la posibilidad de compararlas con la libreria <ctime>
        int priority;
    public:
        // Constructor vacio
        Project(){

        }
        // getters y setters
        void setName(string name){
            this->name = name;
        }
        string getName() const {
            return this->name;
        }

        void setPropietary(string propietary){
            this->propietary = propietary;
        }
        string getPropietary(){
            return this->propietary;
        }

        void setDescription(string description){
            this->description = description;
        }
        string getDescription(){
            return this->description;
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

        // Metodos
        void createProject(){
            string name;
            string propietary;
            string description;
            string status;
            string deadline;
            cout << "Nombre del proyecto: ";
            cin >> name;
            cout << "Propietario: ";
            cin >> propietary;
            cout << "Descripcion: ";
            cin >> description;
            /*
            Status puede ser "En progreso", "Terminado", "Pendiente"
            y hago un input para que el usuario pueda elegir uno de esos estados
            */
            cout << "Estado: seleccione una opcion";
            cout << "1. Pendiente";
            cout << "2. En progreso";
            cout << "3. Terminado";
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

            cout << "Fecha limite, digite en formato dd/mm/yyyy sin espacios ni slash:";
            cin >> deadline;
            setName(name);
            setPropietary(propietary);
            setDescription(description);
            setStatus(status);
            setDeadline(deadline);
        };

        void showProject(){
            cout << "Nombre del proyecto: " << getName() << endl;
            cout << "Propietario: " << getPropietary() << endl;
            cout << "Descripcion: " << getDescription() << endl;
            cout << "Estado: " << getStatus() << endl;
            cout << "Fecha limite: " << getDeadline() << endl;
        };

        bool operator<(const Project& other) const { // Sobrecarga del operador < para poder comparar objetos de tipo Project
        // Define tu lógica de comparación aquí
        return priority < other.priority; // Por ejemplo, puedes comparar por prioridad
        };
};