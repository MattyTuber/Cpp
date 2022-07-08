#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	int s, num, num2;
	
	cout << "1. Per MCD\n";
	cout << "2. Per mcm\n";
	cout << "3. Verifica Numero Primo\n";
	
	cout << "Scelta --> ";
	cin >> s;
	
	switch (s){
		case 1:
			cout << "\nInserire Numero --> ";
			cin >> num;
			
			cout << "Inserire Numero --> ";
			cin >> num2;
			
			cout << "MCD --> " << mcd (num, num2);
		break;
		
		case 2:
			cout << "\nInserire Numero --> ";
			cin >> num;
			
			cout << "Inserire Numero --> ";
			cin >> num2;
			
			cout << "mcm --> " << mcm (num, num2);
		break;
		
		case 3:
			cout << "\nInserire Numero --> ";
			cin >> num;
			
			if (primo (num) != 0)
				cout << "Numero Primo";
			else
				cout << "Numero non Primo";
		break;
		
		default:
			cout << "Scelta Errata!!";
		break;
	}
}
