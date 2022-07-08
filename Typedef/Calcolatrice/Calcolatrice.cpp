#include <iostream>
#include <cstdio>
#include <cstdlib>

//Definisco un tipo menu e faccio l'enumerazione a partire da 1
typedef enum {SOMMA = 1, SOTTRAZIONE, MOLTIPLICAZIONE, DIVISIONE, ESCI} menu;

using namespace std;

int main()
{
	menu scelta;
	int a, b;
	bool fine = false;
	
	//Faccio un ciclo che si ripete fino a quando non metto 5 come opzione cioè termino il programma
	do{
		
		cout << "1 - Somma" << endl;
		cout << "2 - Sottrazione" << endl;
		cout << "3 - Moltiplicazione" << endl;
		cout << "4 - Divisione" << endl;
		cout << "Premere 5 per uscire" << endl;
		
		cout << "Scelta --> ";
		scanf ("%d", &scelta);
		
		//Con il costrutto switch case controllo l'opzione inserita senza usare gli if 
		switch (scelta)
		{
			case SOMMA:
				cout << "Inserire i due addendi --> ";
				scanf ("%d %d", &a, &b);
				
				cout << a << " + " << b << " = " << a + b << "\n\n";
				
			break;
			
			case SOTTRAZIONE:
				cout << "Inserire minuendo e sottraendo --> ";
				scanf ("%d %d", &a, &b);
				
				cout << a << " - " << b << " = " << a - b << "\n\n";
				
			break;
			
			case MOLTIPLICAZIONE:
				cout << "Inserire moltilicando e moltiplicatore --> ";
				
				scanf ("%d %d", &a, &b);
				
				cout << a << " X " << b << " = " << a * b << "\n\n";
				
			break;
			
			case DIVISIONE:
				cout << "Inserire quoziente e divisore --> ";
				scanf ("%d %d", &a, &b);
				
				cout << a << " / " << b << " = " << (float) a / b << "\n\n";
				
			break;
			
			//Assegno alla variabile booleana fine il valore di falso, se entro in questo case fine diventa vero e quendi esco anche dal do while
			case ESCI:
				fine = true;
				
			break;
			
			default:
				cout << "Opzione non valida! Reinserire" << "\n\n";
			
			break;
		}
	
	} while (!fine);
	
	return 0;
}
