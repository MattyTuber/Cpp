#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()

{
	
	int i, n, l1, l2, l3, controllo;
	
	cout << "Inserire il numero di terne --> ";
	cin >> n;
	
	for (i=0; i<n; i++)
	
	{
		
		cout << "Inserire un lato --> ";
		cin >> l1;
		
		cout << "Inserire un altro lato --> ";
		cin >> l2;
		
		cout << "Inserire un altro lato --> ";
		cin >> l3;
		
		if ((l1 > l2) && (l1 > l3))
		
		{
			
			controllo = pow(l2, 2) + pow(l3, 2);
		
			if (controllo == pow(l1, 2))
		
				cout << "I lati inseriti formano un triangolo rettangolo" << endl;
			
			else
			
				cout << "I lati inseriti non formano un triangolo rettangolo" << endl;
			
		}
		
		else if ((l2 > l1)&&(l2 > l3))
		
		{
			
			controllo = pow(l1, 2) + pow(l3, 2);
		
			if (controllo == pow(l2, 2))
		
				cout << "I lati inseriti formano un triangolo rettangolo" << endl;
			
			else
			
				cout << "I lati inseriti non formano un triangolo rettangolo" << endl;
			
		}
		
		else
		
		{
			
			controllo = pow(l2, 2) + pow(l1, 2);
		
			if (controllo == pow(l3, 2))
		
				cout << "I lati inseriti formano un triangolo rettangolo" << endl;
			
			else
			
				cout << "I lati inseriti non formano un triangolo rettangolo" << endl;
			
		}
			
	}
	
}
