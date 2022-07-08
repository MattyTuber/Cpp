#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num;
	float sommatoria = 0;
	
	cout << "Inserire numero massimo --> ";
	cin >> num;
	
	while (num != 0){
		sommatoria += 1/pow(num,2);
		
		num--;
	}
	
	cout << "Sommatoria --> " << sommatoria;
	
	return (0);
}
