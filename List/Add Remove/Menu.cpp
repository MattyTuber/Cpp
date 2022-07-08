#include <iostream>
#include <list>

using namespace std;

void menu(){
	cout << "1. Aggiungi in Coda";
	cout << "\n2. Aggiungi in Testa";
	cout << "\n3. Aggiungere nodo Generico";
	cout << "\n4. Eliminare nodo Generico";
	cout << "\n10. Exit";
}

int main(){
	int choice, num, N;
	list <int> lista;
	list <int>::iterator iter;
	
	while(true){
		system("cls");
		menu();
		cout << "\n\nScelta --> ";
		cin >> choice;
		
		switch(choice){
			case 1:
				cout << "Inserire Numero --> ";
				cin >> num;
				
				lista.push_back(num);	
			break;
			
			case 2:
				cout << "Inserire Numero --> ";
				cin >> num;
				
				lista.push_front(num);	
			break;
			
			case 3:
				cout << "Inserire Posizione --> ";
				cin >> N;
				
				for (iter = lista.begin(),num = 0; num < N; iter++, num++){}
				
				cout << "Inserire Numero --> ";
				cin >> num;
				
				lista.insert(iter, num);
			break;
			
			case 4:
				cout << "Inserire Posizione --> ";
				cin >> N;
				
				for (iter = lista.begin(),num = 0; num < N; iter++, num++){}
				
				lista.erase(iter);
			break;
			
			case 10:
				cout << "\n\n";
				for(auto i : lista)
					cout << "[" <<  i << "]\t";
			exit(10);
				
			default:
				cout << "Scelta non valida!!";
			break;
		}
	}
}
