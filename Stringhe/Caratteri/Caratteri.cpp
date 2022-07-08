#include <iostream>
#include <string>

using namespace std;

int main()
{
	char a [256];
	int i, num = 0, upper = 0, lower = 0, other = 0;

	cout << "Inserire una stringa --> ";
	gets(a);

	for (i = 0; a [i] != '\0'; ++i)
	{
		if (a [i] >= 48 && a [i] <= 57)
			num++;
		else if (a [i] >= 65 && a [i] <= 90)
			upper++;
		else if (a [i] >= 97 && a [i] <= 122)
			lower++;
		else
			other++;
	}

	cout << "Cifre --> "<< num << endl;
	cout << "Maiuscole --> "<< upper << endl;
	cout << "Minuscole --> "<< lower << endl;
	cout << "Altri --> "<< other;

	return 0;
}