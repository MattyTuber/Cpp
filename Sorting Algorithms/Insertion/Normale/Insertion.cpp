#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, j, temp, key;
	
	cout << "Inserire la dimensione del vettore --> ";
	cin >> N;
	
	int vet[N];

	for (i = 0; i < N; ++i)
	{
		cout << "Inserie un valore --> ";
		cin >> vet[i];
	}
	
	for (j = 1; j < N; ++j)
	{
		key = vet[j];

		for (i = j-1; i>=0 && vet[i]>key; i--)
			vet[i+1] = vet[i];
		vet[i+1] = key;
	}
	
	for (i = 0; i < N; ++i)
	{
		cout << vet[i] << "\t";
	}

	return 0;
}
