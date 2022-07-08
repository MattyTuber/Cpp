#include <iostream>
#include <stdlib.h>

using namespace std;

int main()

{

	int altezza, base, a, p;

	cout << "Inserire la base --> ";
	cin >> base;

	cout << "Inserire l'altezza --> ";
	cin >> altezza;

	a = base * altezza;

	p = base * 2 + altezza * 2;

	cout << "Area: " << a << endl;

	cout << "Perimetro: " << p << endl;

	system("pause");

}