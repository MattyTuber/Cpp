#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include <vector>
/*
    Gestione articoli biblioteca
*/
/*  
    Classe articolo --> Attributi : Tipo ; Medodi : Costruttore, Distruttore, GetType e metodi virtuali 
*/
struct utente_s
{
    std::string nome;
    std::string cognome;
    std::vector<int> codice_utente;
};
typedef utente_s utente;

class articolo {
    public: 

    ~articolo(){};

    std::string GetType() { return tipo_p;}
    virtual void SetTitle(std::string titolo) {}
    virtual void SetAuthor(std::string autore) {}
    virtual std::string GetTitle() {return tipo_p;}
    virtual std::string GetAuthor() {return tipo_p;}

    protected: 
    
    std::string tipo_p;

};
/* 
    Classe libro ---> Attributi: Autore, titolo e Tipo (ereditato) = libro ; Metodi: metodi accesso (getter) e metodi Setter
*/
class libro : public articolo {

    public:

    libro(std::string autore, std::string titolo): articolo(){

        titolo_p = titolo;
        autore_p = autore;
        tipo_p = "libro";
    }

    libro() {

        tipo_p = "libro";
    }

    std::string GetTitle() {return titolo_p;}
    std::string GetAuthor() {return autore_p;}

    void SetTitle(std::string titolo){

        titolo_p = titolo;

    }

    void SetAuthor(std::string autore){

        autore_p = autore;

    }
    private:

        std::string autore_p;
        std::string titolo_p;
};
/* 
    Classe CD ---> Attributi: Autore, titolo e Tipo (ereditato) = CD ; Metodi: metodi accesso (getter) e metodi Setter
*/
class CD : public articolo {

    public:

    CD(std::string autore, std::string titolo): articolo(){

        titolo_p = titolo;
        autore_p = autore;
        tipo_p = "CD";
    }

    CD() {

        tipo_p = "CD";
    }

    ~CD() {}

    std::string GetTitle() {return titolo_p;}
    std::string GetAuthor() {return autore_p;}

    void SetTitle(std::string titolo){

        titolo_p = titolo;

    }

    void SetAuthor(std::string autore){

        autore_p = autore;

    }


    private:
    
    std::string  titolo_p;
    std::string  autore_p;

};
/* 
    Funzione per aggiungere un articolo alla lista. 
 */
void add_article(std::list<articolo*>& lista){

    int app;
    std::cout << "Inserire  \n 1. Libro\n 2. CD \n"; 
    std::cin >> app;
    getchar();

    articolo* articolo_tmp;
    std::string string_app;
    switch (app)
    {
    case 1:

        if(lista.size() < 10 ) {

            articolo_tmp = new libro;
            

            std::cout << "inserisci titolo libro" << std::endl;
            getline(std::cin, string_app);
            articolo_tmp->SetTitle(string_app);
            std::cout << "inserisci autore libro" << std::endl;
            getline(std::cin, string_app);
            articolo_tmp->SetAuthor(string_app);


            lista.push_back(articolo_tmp);

            std::cout << "ARTICOLO INSERITO CON SUCCESSO" << std::endl;
        }
        else 

            std::cout << "RAGGIUNTO LIMITE DI ARTICOLI" << std::endl;
        break;
    case 2 :


        if(lista.size()< 10){

            articolo_tmp = new CD;

            std::cout << "inserisci titolo CD" << std::endl;
            getline(std::cin, string_app);
            articolo_tmp->SetTitle(string_app);
            std::cout << "inserisci autore CD" << std::endl;
            getline(std::cin, string_app);
            articolo_tmp->SetAuthor(string_app);

            lista.push_back(articolo_tmp);

            std::cout << "ARTICOLO INSERITO CON SUCCESSO\n\n" << std::endl;

        }
        else 

            std::cout << "RAGGIUNTO LIMITE DI ARTICOLI" << std::endl;
        break;
    
    default:

        EXIT_SUCCESS;
        break;
    }



}
/*  
    Funzione per stampare la lista.
*/
void stampa_lista(std::list<articolo*>& lista){

    for(auto element : lista) {

        std::cout << "Titolo " << element->GetType() << " :\t" << element->GetTitle() << "\t Autore: " <<  element->GetAuthor() << std::endl; 
    }



}
/*  
    Funzione per rimuovere un elemento della lista lista
*/
void rm_article (std::list<articolo*>& lista) {


        articolo* app;
        std::string string_app;
        std::cout << "Inserire titolo \n";
        getline(std::cin, string_app);
        std::list<articolo*>::iterator p = lista.begin();

        for(auto element : lista) {
        
            if (element->GetTitle() == string_app) {
                lista.erase(p);
                break;
            }
            p++;
        }

}
/*
    Controlla che il codice non sia già presente all'interno dell'archivio
*/
bool codice_bool (std::fstream& InFile, std::vector<int> codice) {

    InFile.open("utenti.txt", std::ios::in);

    std::vector<int> codice_app;
    codice_app.resize(10);

    std::string app;

    while(InFile.eof() == false){

        InFile >> app >> app;

        for( auto element : codice_app ) {

            InFile >> element;          

        }

        if(codice_app == codice) {

            InFile.close();
            return true;
        }

    }
    InFile.close();
    return false;


}

void iscrivi_utente(std::fstream& OutFile) {



    utente utente_app;

    utente_app.codice_utente.resize(10);

    OutFile.open("utenti.txt", std::ios::app); 

    std::cout << "inserisci nome" << std::endl;
    getline( std::cin, utente_app.nome);
    OutFile << utente_app.nome << "\t";
    
    std::cout << "Inserisci cognome " << std::endl;
    getline( std::cin, utente_app.cognome);
    OutFile << utente_app.cognome << "\t";

    for(int i = 0; i < utente_app.codice_utente.size(); i++){

        utente_app.codice_utente.at(i) = rand() % 10;
    }

    
    
    for(auto element : utente_app.codice_utente)
        OutFile << element;
    
    OutFile << "\n\n";
    OutFile.close();

    std::cout << "Istrizione avvenuta con successo\n";
}

int main(){

    std::list<articolo*> prestiti;
    std::fstream File_utenti;
    std::fstream File_prestiti;


    int app;

   do
   {
      
    
    std::cout << "1. Inserire nuovo articolo \n2. Rimuovere articolo\n3. Stampare lista\n4. Aggiumgi utente biblioteca\n";
    std::cin >> app;
    getchar();

    switch (app)
    {
    case 1:
        
        add_article(prestiti);
   
        break;
    
    case 2:

        rm_article(prestiti);
    
        break;

    case 3:

        stampa_lista(prestiti);

        break;
    case 4: 

       iscrivi_utente(File_utenti);
        
        break;

    
    default:
        return 0;
        break;
    }

   }while (true);
   
}