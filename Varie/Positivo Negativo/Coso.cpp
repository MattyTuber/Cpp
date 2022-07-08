#include <iostream>
#include <stdlib.h>

using namespace std;

int main()

{
	
	int n1, n2;
	
	float divisione;
	
	cout << "Inserire un numero --> ";
	cin >> n1;
	
	cout << "Inserire un numero --> ";
	cin >> n2;
	
	if (n1 >= 0 && n2 >= 0)
	
		cout << "Somma: " <<n1 + n2<< endl;
	
	else if (n1 < 0 && n2 < 0)
	
		cout << "Prodotto: " <<n1 * n2<< endl;
	
	else
	
	{
	
		divisione = n1 / n2;	
		cout << "Divisione: " <<divisione<< endl;
	
	}
		
	return 0;
	
}
