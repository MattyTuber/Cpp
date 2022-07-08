#include <iostream>

using namespace std;

bool pari (int num);

int main()
{
	int a;
	bool num;
	
	cout << "Inserire un numero --> ";
	cin >> a;
	
	num = pari (a);
	
	if (num)
		cout << "Pari";
	else
		cout << "Dispari";
}

bool pari (int num)
{
	if (num % 2 == 0)
		return true;
	else
		return false;
}
