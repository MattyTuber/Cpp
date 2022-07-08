#include <iostream>

using namespace std;

class dispenser{
	public:
		dispenser(){
			capacity = 500;
			content = 500;
			empty = 10;
		}
		
		int getContent(){
			return content;
		}
		
		void eroga(){
			cout << "Erogazione...\n";
			if (content >= 10)
				content -= empty;
			else
				cout << "Sapone Insufficiente!!\n";
		}
		
		void ricarica(){
			cout << "\n\nRicaricando...\n";
			content = capacity;
		}
		
	private:
		int capacity;
		int content;
		int empty;
};

int main(){
	dispenser soap;
	
	soap.eroga();
	cout << "Contenuto --> " << soap.getContent();
	soap.ricarica();
	cout << "Contenuto --> " << soap.getContent();
}
