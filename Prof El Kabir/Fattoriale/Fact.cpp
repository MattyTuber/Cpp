#include <iostream>

using namespace std;

int main()
{
	int num, fact = 1, i;
	
	cout << "Inserire un numero --> ";
	cin >> num;
	
	for (i=1; i<=num; i++)
		fact *= i;
		
	cout << "Fattoriale --> " << fact;
}
