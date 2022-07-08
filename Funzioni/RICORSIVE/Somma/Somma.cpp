#include <iostream>

using namespace std;

long long somma (int numero);

int main()
{
	int num;
	
	cout << "Inserire un numero --> ";
	cin >> num;
	
	cout << "Somma di tutti i numeri di " << num << " --> " << somma (num);
}

long long somma(int n)
{
	if (n <= 1)
		return 1;
	else
		return n + somma (n-1);
}
