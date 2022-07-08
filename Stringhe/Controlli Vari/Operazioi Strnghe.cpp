#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <string.h>

using namespace std;

int main()
{
	char a[256], b [256], car, carattere [2];
	int len, i, cont = 0;
	string str, stri;
	
	cout << "Inserire un carattere e una stringa --> ";
	scanf ("%c ", &car);
	gets(a);
	
	len = strlen (a);
	
	if (isdigit (car))
	{
		if (len >=  car - '0')
			cout << "La stringa " << a << " ha lunghezza maggiore di " << car;
		else
			cout << "La stringa " << a << " ha lunghezza minore di " << car;
	}
	else if (isalpha (car))
	{
		car = tolower (car);
		
		for (i=0; i<=len; i++)
		{
			a[i] = tolower (a [i]);
			
			if (a [i] == car)
				cont++;
		}
		
		cout << "La stringa " << a << " contiene " << cont << " volte la lettera " << car;
	}
	else 
	{
		carattere [0] = car;
		
		strcat (a, " ");
		
		strcat (a, carattere);
		
		cout << "Stringa --> " << a << endl;
		
		cout << "Inserire una nuova stringa --> ";
		gets (b);
		
		strcat (a, b);

		cout << "Stringa --> " << a;
	}
}

