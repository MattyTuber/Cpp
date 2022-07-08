#include <iostream>
#include <string.h>

using namespace std;

struct cellulare{ 
	char modello [20];
	
	float prezzo;
};

void input (struct cellulare *euronics, int Neu, struct cellulare *apple, int Nap);
int compare (struct cellulare *eu, int Neu, struct cellulare *app, int Nap);

int main()
{
	int Neu, Nap, i, j;
	
	cout << "Numero di Telefoni Euronics --> ";
	cin >> Neu;
	
	cout << "Numero di Telefoni Apple Store --> ";
	cin >> Nap;
	
	struct cellulare euronics [Neu];
	
	struct cellulare apple [Nap];
	
	input (euronics, Neu, apple, Nap);
	
	cout << compare (euronics, Neu, apple, Nap) << " telefoni sono venduti in entrambe gli store";
	
	return 0;
}

void input (struct cellulare *euronics, int Neu, struct cellulare *apple, int Nap)
{
	int i, j;
	
	cout << "Euronics: " << endl;
	
	for (i=0; i<Neu; i++){
		getchar();		
		cout << "Inserire un Modello --> ";
		gets (euronics[i].modello);
		
		cout << "Insrirne il Prezzo --> ";
		cin >> euronics[i].prezzo;
	}
	
	cout << "Apple Store: " << endl;
	
	for (i=0; i<Nap; i++){
		getchar();	
		cout << "Inserire un Modello --> ";
		gets (apple[i].modello);
		
		cout << "Insrirne il Prezzo --> ";
		cin >> apple[i].prezzo;
	}
}

int compare (struct cellulare *eu, int Neu, struct cellulare *app, int Nap)
{
	int i, j, result;
	int cont = 0;
	
	for (i=0; i<Nap; i++){
		for (j=0; j<Neu; j++){
			result = strcmp (eu[j].modello, app[i].modello);
			
			if (result == 0)
				cont++;
		}
	}
	
	return cont;
}
