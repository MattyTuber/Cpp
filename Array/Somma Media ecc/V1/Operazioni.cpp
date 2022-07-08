#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int somma, media, massimo, minimo, N;
	somma = 0;

	cout << "Inserire la dimensione dell' Array --> ";
	cin >> N;

	int a[N];

	for (int i=0; i<N; i++)
	{
		cout << "Inserire un valore --> ";
		cin >> a[i];

		somma += a[i];
	}

	media = somma / N;

	max = std::max_element(a, a + N); //<---

	min = std::min_element(a, a + N); //<---

	cout << "Somma --> " << somma;
	cout << "Media --> " << media;
	cout << "Massimo --> " << massimo;
	cout << "Minimo --> " << minimo;
	
	return 0;
}