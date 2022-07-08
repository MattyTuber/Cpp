#include <iostream>

using namespace std;

int main()
{
	int N, i;

	cout << "Inserire il numero di valori --> ";
	cin >> N;

	int vett[N];

	for (i = 0; i < N; ++i)
	{
		cout << "Inserire un valore --> ";
		cin >> vett[i];
	}

	cout << "Pari --> ";

	for (i = 0; i < N; ++i)
	{
		if (vett[i] % 2 == 0)

			cout << vett[i] << " ";
	}

	cout << endl << "Dispari --> ";

	for (i; i >= 0; --i)
	{
		if (vett[i] % 2 != 0)

			cout << vett[i] << " ";
	}
	
	return 0;
}