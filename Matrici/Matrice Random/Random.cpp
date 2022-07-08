#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	int NR, NC, i, j, p = 0, d = 0;

	char e = 138;

	cout << "Numero di righe --> ";
	cin >> NR;

	cout << "Numero di colonne --> ";
	cin >> NC;

	int matrice [NR] [NC];

	srand(time(NULL));

	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			matrice [i] [j] = rand()%100;
		}
	}

	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			if (matrice [i] [j] % 2 == 0)
				p++;
			else
				d++;

			cout << matrice [i] [j] << "\t";
		}

		cout << "\n\n\n";
	}

	cout << "La matrice " << e << " composta da " << p << " valori PARI e " << d << " valori DISPARI";

	return 0;
}