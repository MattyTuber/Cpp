#include <iostream>
#include <string>

using namespace std;

int main()
{
	char a [256];
	int i, num = 0;

	cout << "Inserire una stringa --> ";
	gets(a);

	for (i = 0; a [i] != '\0'; ++i)
		if (a [i] >= 48 && a [i] <= 57)
			num++;

	cout << "Cifre --> "<< num;

	return 0;
}