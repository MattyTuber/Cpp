#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int NR, NC, i, j, somma, max, min;

	float media;

	somma = 0;

	cout << "Inserire il numero di righe --> ";
	cin >> NR;

	cout << "Inserire il numero di colonne --> ";
	cin >> NC;

	int matrice [NR] [NC];

	for (i=0; i<NR; i++)
	{
		for (j=0; j<NC; j++)
		{
			cout << "Inserire un numero --> ";
			cin >> matrice [i] [j];

			somma += matrice [i] [j];
		}
	}

 	max = matrice [0] [0];
	min = matrice [0] [0];

	for (i=0; i<NR; i++)
	{
		for (j=0; j<NC; j++)
		{
			if (matrice [i] [j] > max)
				max = matrice [i] [j];
		
			if (matrice [i] [j] < min)
				min = matrice [i] [j];
		}
	}

	media = static_cast <float> (somma) / (NR * NC);

	cout << "Somma --> " << somma << endl;
	cout << "Media --> " << media << endl;
	cout << "Massimo --> " << max << endl;
	cout << "Minimo --> " << min;

	return 0;
}