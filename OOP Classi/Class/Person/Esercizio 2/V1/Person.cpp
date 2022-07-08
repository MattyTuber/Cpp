#include <iostream>

using namespace std;

class persona {
	public:
		string cognome;
		string nome;
		int eta;
		
		persona (string cognome, string nome, int eta);
		~persona ();
		
		void stampa_anagrafica();
		
	private:
		string sur;
		string name;
		int age;
};

persona::persona(string cognome, string nome, int eta)
{
	cout << "Constructor\n\n";
	sur = cognome;
	name = nome;
	age = eta;
}

persona::~persona()
{
	cout << "\n\nDestructor";
}

void persona::stampa_anagrafica()
{
	cout << "\nCognome --> " << sur;
	cout << "\nNome --> " << name;
	cout << "\nEta' --> " << age;
}

int main()
{
	persona person("Broglio", "Matteo", 17);
	
	person.stampa_anagrafica();
	
	return 0;
}
