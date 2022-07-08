#include <iostream>
#include <stdlib.h>

using namespace std;

int main()

{

	int a, b, somma;

	cout << "Inserire un numero --> ";
	cin >> a;

	cout << "Inserire un altro numero --> ";
	cin >> b;

	somma = a + b;

	cout << "L' operazione " << a << " + " << b << " = " << somma << endl;

	system("pause");

}