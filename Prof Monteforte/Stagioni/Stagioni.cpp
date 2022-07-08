#include <iostream>

using namespace std;

int main()
{
	int mese, giorno;
	
	cout << "Inserire il mese --> ";
	cin >> mese;
	
	switch (mese)
	{
		case 1:
		case 2:
			cout << "Inverno";
		break;
		
		case 4:
		case 5:
			cout << "Primavera";
		break;
		
		case 7:
		case 8:
			cout << "Estate";
		break;
		
		case 10:
		case 11:
			cout << "Autunno";
		break;
			
		case 3:
			cout << "Specificare il giorno --> ";
			cin >> giorno;
			
			if (giorno < 21)
				cout << "Inverno";
			else
				cout << "Primavera";
		break;
		
		case 6:
			cout << "Specificare il giorno --> ";
			cin >> giorno;
			
			if (giorno > 21)
				cout << "Estate";
			else
				cout << "Primavera";
		break;
			
		case 9:
			cout << "Specificare il giorno --> ";
			cin >> giorno;
			
			if (giorno > 21)
				cout << "Autunno";
			else
				cout << "Estate";
		break;
			
		case 12:
			cout << "Specificare il giorno --> ";
			cin >> giorno;
			
			if (giorno > 22)
				cout << "Inverno";
			else
				cout << "Autunno";
		break;
		
		default:
			cout << "Errore!!";
		break;
	}
}
