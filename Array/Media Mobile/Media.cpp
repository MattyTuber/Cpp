#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i;
	float media;

	cout << "Inserire la dimensione del vettore --> ";
	cin >> N;

	float vett[N];

	for (i = 0; i < N; ++i)
	{
		cout << "Inserire un valore --> ";
		cin >> vett[i];
	}

	cout << endl;

	for (i = 0; i < N-2; ++i)
	{
		media = (vett [i] + vett [i+1] + vett [i+2]) / 3.00;

		cout << i + 1 << " Media --> " << media << endl;
	}
	
	return 0;
}