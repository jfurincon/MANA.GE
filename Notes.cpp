#include <iostream>

using namespace std;

class Note{
    private:
        string title;
        string content;
        string author;
        string reaction;
    public:
        // Constructor vacio
        Note(){

        }
        // getters y setters
        void setTitle(string title){
            this->title = title;
        }
        string getTitle(){
            return this->title;
        }

        void setContent(string content){
            this->content = content;
        }
        string getContent(){
            return this->content;
        }

        void setAuthor(string author){
            this->author = author;
        }
        string getAuthor(){
            return this->author;
        }

        void setReaction(string reaction){
            this->reaction = reaction;
        }
        string getReaction(){
            return this->reaction;
        }

        // Metodos
        void createNote(){
            string title;
            string content;
            string author;
            string reaction;

            cout << "Ingrese el titulo de la nota: ";
            cin >> title;
            setTitle(title);

            cout << "Ingrese el contenido de la nota: ";
            cin >> content;
            setContent(content);

            cout << "Ingrese el autor de la nota: ";
            cin >> author;
            setAuthor(author);

            cout << "Ingrese la reaccion de la nota: 1. <3, 2. :), 3. :(, 4. >:(";
            cin >> reaction;
            if(reaction == "1"){
                reaction = "<3";
            }else if(reaction == "2"){
                reaction = ":)";
            }else if(reaction == "3"){
                reaction = ":(";
            }else if(reaction == "4"){
                reaction = ">:(";
            }
            setReaction(reaction);
        }
};