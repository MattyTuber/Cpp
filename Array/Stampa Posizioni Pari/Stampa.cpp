#include <iostream>

using namespace std;

int main()
{
	int N;

	cout << "Insrire il numero di valori --> ";
	cin >> N;

	int a[N];

	for (int i=0; i<N; i++)
	{
		cout << "Inserire un valore --> ";
		cin >> a[i];
	}

	for (int i = 0; i < N; i=i+2)
	{
		cout << a[i] << endl;
	}
	
	return 0;
}