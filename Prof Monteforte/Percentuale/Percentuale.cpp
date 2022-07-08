/*Ad un rappresentante spetta, oltre ad una percentuale sulle vendite effettuate in una
settimana, un premio in denaro se la percentuale è superiore a 500,00 €.
Tale premio varia secondo il valore della sua percentuale.
Dati il nome e la percentuale di un rappresentante calcolare il premio e la somma totale che
gli spetta.
Si suppone che il premio sia il seguente.
? € 50,00 se la percentuale è inferiore a 1000,00 €.
? € 100,00 se la percentuale è inferiore a 1500,00 €.
? € 200,00 se la percentuale*/

#include <iostream>

using namespace std;

int main()
{
	char nome [20];
	int percentuale, premio, tot;
	
	cout << "Inserire Nome --> ";
	cin >> nome;
	
	cout << "Inserire Percentuale --> ";
	cin >> percentuale;
	
	if (percentuale < 1000)
		premio = 50;
		
		else if (percentuale < 1500)
			premio = 100;
			
			else if (percentuale >= 1500)
				premio = 200;
				
				else
					cout << "Errore!!";
					
	tot = percentuale + premio;
		
	cout << "\n" << nome << endl;
	cout << "Premio --> " << premio << endl;
	cout << "Totale --> " << tot;
}
