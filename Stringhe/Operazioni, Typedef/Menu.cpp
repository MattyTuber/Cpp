#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstdio>

typedef enum {REWRITE = 1, CAT, LOWER, UPPER, SCAN, END} menu;

using namespace std;

int main()
{
	char a [256], b [256];
	bool end = false;
	menu op;
	int i, num = 0, upper = 0, lower = 0, space = 0, other = 0;
	
	cout << "Inserire una stringa --> ",
	gets (a);
	
	cout << "1 - Riscrivi\n2 - Continuare a scrivere dal fondo\n3 - Convertire in minuscolo\n4 - Convertire in maiuscolo\n5 - Scansiona la stringa\n6 - Finire il programma\n\n";
	
	do{
		cout << "\n\nChe operazione vuoi eseguire --> ";
		scanf("%d", &op);
		getchar();
		
		switch (op)
		{
			case REWRITE:
				cout << "Reinserie la stringa --> ";
				gets(a);
				
				cout << a;
				
			break;
				
			case CAT:
				cout << a;
				gets (b);
				
				strcat (a, b);
				
				cout << a;
				
			break;
				
			case LOWER:
				for (i=0; a [i] !='\0'; i++)
					a [i] = (char) tolower(a [i]);
					
				cout << a;
				
			break;
				
			case UPPER:
				for (i=0; a [i] !='\0'; i++)
					a[i] = (char) toupper(a [i]);
					
				cout << a;
				
			break;
				
			case SCAN:
				for (i = 0; a [i] != '\0'; ++i)
				{
					if (isdigit(a [i]))
						num++;
					else if (isupper (a [i]))
						upper++;
					else if (islower (a [i]))
						lower++;
					else if (isspace (a [i]))
						space++;
					else
						other++;
				}
			
				cout << "Cifre --> "<< num << endl;
				cout << "Maiuscole --> "<< upper << endl;
				cout << "Minuscole --> "<< lower << endl;
				cout << "Spazzi --> "<< space << endl;
				cout << "Altri --> "<< other;
				
			break;
				
			case END:
				end = true;
				
			break;
				
			default:
				cout << "Errore, Reinserire";
				
			break;
		}	
	
	}while (!end);
}
