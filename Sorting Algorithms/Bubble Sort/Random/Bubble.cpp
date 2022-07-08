#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, j, m, temp;
	bool scambi = true;
	
	srand(time(NULL));
	
	cout << "Inserire la dimensione del vettore --> ";
	cin >> N;
	
	int vet[N];

	for (i = 0; i < N; ++i)
	{
		vet[i] = rand()%99+1;
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
		
		for (m = 0; m < N; ++m)
		{
			cout << vet[m] << "\t";
		}
		
		cout << "\n\n\n";
	}

	return 0;
}

