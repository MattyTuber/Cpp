#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, j, min; 
	char temp [256];
	
	cout << "Inserire il numero di stringhe --> ";
	cin >> N;
	
	getchar ();
	
	char a [N] [256];
	
	for (i=0; i < N; i++)
	{
		cout << "Inserire una stringa --> ";
		gets (a [i]);
	}
	
	for (i=0; i < N; i++)
	{
		cout << a [i] << endl;
	}
	
	for (i = 0; i < N-1; ++i)
	{
		min = i;

		for (j = i+1; j < N; ++j)
		{
			if (strcmp (a [j], a [min]) < 0)
				min = j;
		}		
		
		strcpy (temp, a [min]);
		
		strcpy (a [min], a [i]);
		
		strcpy (a [i], temp);
	}
	
	cout << endl;
	
	for (i = 0; i < N; ++i)
	{
		cout << a[i] << "\t";
	}

	return 0;
}


