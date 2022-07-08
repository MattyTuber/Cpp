#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char a [100];
	int cont = 0;

	cout << "Inserire una stringa --> ";
	gets (a);

	while (a [cont] != '\0')
	{
		a [cont] = (char) toupper (a [cont]);
	
		cout << a[cont];
		
		cont++;
	}

	return 0;
}
