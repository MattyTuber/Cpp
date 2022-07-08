#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int swap(int *vet, int i, int min);

int main(int argc, char const *argv[])
{
	int N, i, j, temp, min; 
	
	srand(time(NULL));
	
	cout << "Inserire la dimensione del vettore --> ";
	cin >> N;
	
	int vet[N];

	for (i = 0; i < N; ++i)
	{
		vet[i] = rand()%N+1;
	}
	
	for (i = 0; i < N-1; ++i)
	{
		min = i;

		for (j = i+1; j < N; ++j)
		{
			if (vet[j] < vet[min])
				min = j;
		}		
		
		swap(vet, i, min);
	}
	
	for (i = 0; i < N; ++i)
	{
		cout << vet[i] << "\t";
	}

	return 0;
}

int swap(int *vet, int i, int min)
{
	int temp;
	
	temp = vet[min];

	vet[min] = vet[i];

	vet[i] = temp;
}
