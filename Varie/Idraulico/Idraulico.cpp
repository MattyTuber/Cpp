#include <iostream>

using namespace std;

#define costo_h 40

int main()

{
	
	float ore, materiale, totale;
	
	cout << "Inserire il costo del materiale: ";
	cin >> materiale;
	
	cout << "Inserire il numero di ore: ";
	cin >> ore;
	
	totale = ore * costo_h + materiale;
	
	if (totale > 100)
	
		cout << "Il totale e' di "<<totale<<" euro" << endl;
		
	else
		cout <<"Il totale e' di 100 euro" << endl;
		
	return 0;		
	
}

