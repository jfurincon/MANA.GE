#include <iostream>

using namespace std;

// la clase login contendra atributos correspondientes a una persona que quiera usar el sistema
class Login{
    private:
        string username;
        string password;
        string name;
        string email;
        string phone;
    public:
    // Constructor vacio
    Login(){

    }
    // getters y setters
    void setUsername(string username){
        this->username = username;
    }
    string getUsername(){
        return this->username;
    }

    void setPassword(string password){
        this->password = password;
    }
    string getPassword(){
        return this->password;
    }

    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }

    void setEmail(string email){
        this->email = email;
    }
    string getEmail(){
        return this->email;
    }

    void setPhone(string phone){
        this->phone = phone;
    }
    string getPhone(){
        return this->phone;
    }

    // Metodos
    void registerUser(){
        string username;
        string password;
        string name;
        string email;
        string phone;
        /*
        WARNING:
        Tuve un problema con los cin, no me permitia ingresar el nombre completo. Por el momento
        la solucion es ingresar el nombre completo sin espacios.
        */
        cout << "Ingrese el usuario que va a utilizar: ";
        cin >> username;
        cout << "Cree una contraseña: ";
        cin >> password;
        cout << "Ingrese su nombre completo: ";
        cin >> name;
        cout << "Ingrese su email: ";
        cin >> email;
        cout << "Ingrese su numero de telefono: ";
        cin >> phone;
        setUsername(username);
        setPassword(password);
        setName(name);
        setEmail(email);
        setPhone(phone);
    }

    bool loginAttempt(){
        string username;
        string password;
        cout << "Ingrese su usuario: ";
        cin >> username;
        cout << "Ingrese su contraseña: ";
        cin >> password;
        if(username == getUsername() && password == getPassword()){
            cout << "Bienvenido " << getName() << endl;
            return true;
        }else{
            cout << "Usuario o contraseña incorrectos" << endl;
            return false;
        }
    }
};