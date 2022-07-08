#include <iostream>

using namespace std;

class person {       
  	public:
    	void getName();
    	void getSurname();
    	
		void outName();
    	void outSurname();
    	
    private:
    	string nome;
    	string cognome;
};

void person::getName()
{
	cout << "Insert Name --> ";
	cin >> nome;
}

void person::getSurname()
{
	cout << "Insert Surname --> ";
	cin >> cognome;
}

void person::outName()
{
	cout << "Nome --> " << nome;
}

void person::outSurname()
{
	cout << "Cognome --> " << cognome;
}

int main()
{	
	person persona;
	
	persona.getName();
	persona.getSurname();
	
	persona.outName();
	cout << "\n";
	persona.outSurname();
	
	return 0;
}
