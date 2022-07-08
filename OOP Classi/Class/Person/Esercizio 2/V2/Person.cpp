#include <iostream>

using namespace std;

//Creazione prima classe

class persona {
	public:
		string cognome;
		string nome;
		int eta;
		
		persona ();
		~persona ();
		
		void getCognome();
		void getNome();
		void getEta();
		
		void stampa_anagrafica();
		
	private:
		string sur;
		string name;
		int age;
};

persona::persona()
{
	;
}

persona::~persona()
{
	;
}

void persona::getCognome()
{
	cout << "Inserire Cognome --> ";
	cin >> cognome;
}

void persona::getNome()
{
	cout << "Inserire Nome --> ";
	cin >> nome;
}

void persona::getEta()
{
	cout << "Inserire Eta --> ";
	cin >> eta;
}

void persona::stampa_anagrafica()
{
	cout << "\nCognome --> " << cognome;
	cout << "\nNome --> " << nome;
	cout << "\nEta' --> " << eta;
}

int main()
{
	persona person1;
	persona person2;
	
	person1.getCognome();
	person1.getNome();
	person1.getEta();
	
	cout << "\n";
	
	person2.getCognome();
	person2.getNome();
	person2.getEta();
	
	if (person1.eta == person2.eta)
		cout << "Le persone sono coetanee";
	
	else{
		person1.stampa_anagrafica();
		cout << "\n";
		person2.stampa_anagrafica();
	}
	
	return 0;
}
