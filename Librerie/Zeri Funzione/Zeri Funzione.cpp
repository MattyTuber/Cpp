#include <iostream>
#include <cmath>
#include "bisection.h"

using namespace std;

int main()
{
	int xmin, xmax;
	double bi;
	
	cout << "Inserire X Minimo --> ";
	cin >> xmin;
	
	cout << "Inserire X Massimo --> ";
	cin >> xmax;
	
	bi = bisection(xmin, xmax);
	
	cout << "Bisezione --> " << bi;
}
