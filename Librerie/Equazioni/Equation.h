#include <iostream>
#include <cmath>

using namespace std;

void eq (int a, int b, int c){
	int delta;
	float result, result2;
	
	if (a == 0){
		cout << "Non equazione di secondo grado!!";
		exit (1);
	}
	
	delta = pow(b, 2) -4 * a * c;
	cout << "\nDelta --> " << delta << endl;
	
	if (delta < 0)
		cout << "\nImpossibile!!";
	
	else if (delta == 0){
		result = -b / (2 * a);
		cout << "\nX1 --> " << result;
	}
		
	else{
		result = (-b + sqrt(delta)) / (2 * a);
		result2 = (-b - sqrt(delta)) / (2 * a);
		
		cout << "\nX1 --> " << result << endl;
		cout << "\nX2 --> " << result2;
	}
}
