#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <string.h>

using namespace std;

int main()
{
	char a[256], b [256];
	int cont = 0, i;
	
	cout << "Inserire uns stringa --> ";
	gets (a);
	
	cout << "Lunghezza --> " << strlen (a) << endl;
	
	//Controllo se il primo carattere inserito (a [0]) sia una lettera
	if (isalpha (a[0]))
	{
		//Converto la lettera in maiuscolo
		a[0] = toupper (a[0]);
		
		cout << "Primo Carattere: Alfabetico --> " << a << endl;
	}
	//Controllo se è un numero
	else if (isdigit (a[0]))
		cout << "Primo Carattere: Numerico" << endl;
	//Se non è alfanumerico entro nell'else
	else
		cout << "Primo Carattere: Non Alfanumerico" << endl;
		
	cout << "Inserire una nuova stringa --> ";
	gets (b);
	
	//Concateno a e b, a assumerà il valore di a e b concatenati
	strcat (a, b);
	
	cout << "Nuova Stringa --> " << a << endl;
	
	//Scansiono carattere per carattere la stringa e se trovo una a incremento il contatore e la sostituisco con un *
	for (i=0; i <= strlen (a); i++)
	{
		if (a [i] == 'a')
		{
			cont++;
			
			a[i] = '*';
		}
	}
	
	cout << "La stringa contiene " << cont << " volte la lettera a" << endl;
	cout << "Stringa Convertita --> " << a;
	
	return 0;
}
