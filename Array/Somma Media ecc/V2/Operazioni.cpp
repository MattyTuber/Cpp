#include <iostream>

using namespace std;

int main()
{
	float media;
	int somma, max, min, N, i;
	somma = 0;

	cout << "Inserire la dimensione dell' Array --> ";
	cin >> N;

	int a[N];

	for (i=0; i<N; i++)
	{
		cout << "Inserire un valore --> ";
		cin >> a[i];

		somma += a[i];
	}

	max = a[0];
	min = a[0];

	for (i = 1; i < N; ++i)
	{
		if (a[i] > max)
			max = a[i];
		
		if (a[i] < min)
			min = a[i];
	}

	//Eseguo un cast forzato (temporaneo) da int a float perchè un operazione tra due int restituisce in cout un int
	//Facendo così automaticamente anche N diventa float e quindi restituisce un float
	media = static_cast <float> (somma) / N;

	cout << "Somma --> " << somma << endl;
	cout << "Media --> " << media << endl;
	cout << "Massimo --> " << max << endl;
	cout << "Minimo --> " << min;


	return 0;
}