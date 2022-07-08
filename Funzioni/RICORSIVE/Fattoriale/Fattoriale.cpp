#include <iostream>

using namespace std;

long long fatt (int numero);

int main()
{
	int num;
	
	cout << "Inserire un numero --> ";
	cin >> num;
	
	cout << "Fattoriale di " << num << " --> " << fatt (num);
}

long long fatt(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fatt (n-1);
}
