#include <iostream>

using namespace std;

int intero (float num);

float decimale (float num);

int main()
{
	float a, num;
	
	cout << "Inserire un numero --> ";
	cin >> a;
	
	cout << intero (a) << endl;
	
	cout << decimale (a);
}

int intero (float num)
{	
	return num;
}

float decimale(float num)
{
	int app;
	
	app = num;

	return num - app;
}
