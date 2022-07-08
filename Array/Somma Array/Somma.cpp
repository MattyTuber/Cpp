#include <iostream>

using namespace std;

int main()
{
	int n, somma, num, N;
	somma = 0;

	cout << "Inserire la dimensione dell' Array --> ";
	cin >> N;

	int a[N];

	for (int i=0; i<N; i++)
	{
		cout << "Inserire un valore --> ";
		cin >> num;

		somma += num;
	}

	cout << "Somma dei valori inseriti --> " << somma;
	
	return 0;
}