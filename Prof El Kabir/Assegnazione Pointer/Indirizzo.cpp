#include <iostream>

using namespace std;

int main()
{
	int num, num2;
	int *pointer;
	
	cout << "Inserire un numero --> ";
	cin >> num;
	
	pointer = &num;
	
	num2 = *pointer;
	
	cout << "Numero 2 --> " << num2 << endl;
	
	cout << "\nDopo l' assegnazione:\n" << endl;
	cout << "Indirizzo Numero 1 --> " << &num << endl;
	cout << "Indirizzo Numero 2 --> " << &num2 << endl;
	cout << "Indirizzo Pointer --> " << &pointer << endl;
	
}
