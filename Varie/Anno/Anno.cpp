#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int NR, year, i;

	cout << "Inserire il numero di persone --> ";
	cin >> NR;
	
	int mat [NR] [3];

	for (i = 0; i < NR; ++i)
	{
		cout << "Persona " << i+1 << ": " << endl;

		cout << "Giorno --> ";
		cin >> mat [i] [0];

		cout << "Mese --> ";
		cin >> mat [i] [1];

		cout << "Anno --> ";
		cin >> mat [i] [2];

		cout << "\n\n";
	}

	cout << "Inserire un anno --> ";
	cin >> year;

	cout << "Persone nate nel " << year << ": " << endl;

	for (i = 0; i < NR; ++i)
	{
		if (mat [i] [2] == year)
			cout << "Persona " << i+1 << endl;
	}
	
	return 0;
}