#include <iostream>
#include <cstdio>

using namespace std;

int interoDecimale (float num, int *intero, float *decimale);

int main()
{
	float a, decimale;
	int intero;
	
	cout << "Inserire un numero --> ";
	cin >> a;
	
	interoDecimale (a, &intero, &decimale);
	
	printf ("Intero --> %d Decimale --> %f", intero, decimale);
}

int interoDecimale (float num, int *i, float *d)
{	
	int app;
	
	*i = num;
	
	app = num;
	
	*d = num - app;
}
