#include <iostream>
#include <stdlib.h>

using namespace std;

int main()

{

	int a, b, prodotto;

	cout << "Inserisci un valore --> ";
	cin >> a;

	cout << "Inserire un altro valore --> ";
	cin >> b;

	prodotto = a * b;

	cout << "Il prodotto tra " << a << " e " << b << " = " << prodotto << endl;

	system("pause");

}