#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, j, temp, min; 
	
	cout << "Inserire la dimensione del vettore --> ";
	cin >> N;
	
	int vet[N];

	for (i = 0; i < N; ++i)
	{
		cout << "Inserie un valore --> ";
		cin >> vet[i];
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
	}
	
	for (i = 0; i < N; ++i)
	{
		cout << vet[i] << "\t";
	}

	return 0;
}

