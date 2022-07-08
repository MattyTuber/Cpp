#include <iostream>
#include <string>

using namespace std;

int main()
{
	char a [256];
	int i;
	bool trovato = false;

	cout << "Inserire una stringa --> ";
	gets(a);

	for (i = 0; i < 10 && a [i] != '\0'; ++i)
		if (a [i] == 'A')
			trovato = true;
	
	if (trovato == true)
		cout << "Trovato";
	else
		cout << "Non Trovato";
	
	return 0;
}