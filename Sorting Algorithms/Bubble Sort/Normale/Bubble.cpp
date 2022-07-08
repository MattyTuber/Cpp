#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, j, temp;
	bool scambi = true;
	
	cout << "Inserire la dimensione del vettore --> ";
	cin >> N;
	
	int vet[N];

	for (i = 0; i < N; ++i)
	{
		cout << "Inserie un valore --> ";
		cin >> vet[i];
	}
	
	for (i = N-1; i > 0 && scambi; --i)
	{
		scambi = false;

		for (j = 0; j < i; ++j)
		{
			if (vet[j] > vet[j+1])
			{
				scambi = true;

				temp = vet[j];

				vet[j] = vet[j+1];

				vet[j+1] = temp;
			}
		}
	}
	
	for (i = 0; i < N; ++i)
	{
		cout << vet[i] << "\t";
	}

	return 0;
}
