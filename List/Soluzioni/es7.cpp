#include<iostream>
#include<list>
#include<string>
/*
    Gestione libri biblioteca
*/
struct libro_s
{
    /* data */
    std::string titolo_libro;
    std::string autore_libro;
};
typedef libro_s libro;


void add_book(std::list<libro>& lista ) {


    libro book;
    std::string app;
    if(lista.size() < 6) {

        std::cout << "Inserire titolo libro" << std::endl;
        std::getline(std::cin, book.titolo_libro);
        std::cout << "Inserire autore libro" << std::endl;
        std::getline(std::cin, book.autore_libro);

        lista.push_back(book);

        std::cout << "LIBRO AGGIUNTO CORRETTAMENTE!\n";
    }
    else 
        std::cout << "RAGGIUNTO IL LIMITE DI PRESTITI\n";
}

void print_list(std::list<libro> lista) {

    for(auto element : lista) {

        std::cout << "Autore libro ---> " << element.autore_libro << "\t";
        std::cout << "Titolo libro ---> " << element.titolo_libro << "\n";
    }

}

void rm_book (std::list<libro>& lista) {

        libro book_rm;
        std::cout << "Inserire titolo libro \n";
        getline(std::cin, book_rm.titolo_libro );
       
        std::list<libro>::iterator p = lista.begin();

        for(auto element : lista) {
        
            if (element.titolo_libro == book_rm.titolo_libro) {
                lista.erase(p);
                break;
            }
            p++;
        }

}

int main(){

    std::list<libro> prestiti;
    libro libro_tmp;

    std::cout << "Scegliere una delle seguenti opzioni \n";
    std::cout << "1. Aggiungere un libro ai prestiti\n2. Restituzione libro\n3. Stampa libri in prestito\n";
    int app;
    do{
    
    std::cin >> app;
    getchar();
    switch (app)
    {
        case 1 :
       
            add_book(prestiti);

        break;
    
        case 2:

            rm_book(prestiti);
            
        break;

        case 3:

            print_list(prestiti);

        break;
        default:

            return 0;
        
        break;
    }
      

  } while (true);
    

}
