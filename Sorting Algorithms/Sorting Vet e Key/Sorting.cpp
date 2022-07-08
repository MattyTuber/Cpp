#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, j, temp, min; 
	
	srand(time(NULL));
	
	cout << "Inserire la dimensione del vettore --> ";
	cin >> N;
	
	int vet[N], key[N];

	for (i = 0; i < N; ++i)
	{
		cout << "Inserire un valore --> ";
		cin >> vet[i];
		cout << "Inserire il valore corrispondente nella chiave --> ";
		cin >> key [i];
	}
	
	for (i = 0; i < N-1; ++i)
	{
		min = i;

		for (j = i+1; j < N; ++j)
		{
			if (vet[j] < vet[min])
				min = j;
		}		
		
		temp = vet[min];

		vet[min] = vet[i];

		vet[i] = temp;

		temp = key [min];

		key [min] = key [i];

		key [i] = temp;

	}
	
	for (i = 0; i < N; ++i)
	{
		cout << vet[i] << "\t";
	}

	return 0;
}
