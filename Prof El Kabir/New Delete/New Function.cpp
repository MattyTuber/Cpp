#include <iostream>

using namespace std;

int main()
{
	double *var = new double(25);
	double *vet = new double[10];
	
	cout << "Variabile Double: \n\n";
	
	cout << "Valore Var --> " << *var << endl;
	
	cout << "Inserire Var --> ";
	cin >> *var;
	
	cout << "Valore Var --> " << *var << endl;
	
	cout << "\nVettore Double: \n\n";
	
	for(int i=0; i<10; i++){
		cout << "Inserire un Valore --> ";
		cin >> vet[i];
	}
	
	for(int i=0; i<10; i++){
		cout << vet[i] << "\t";
	}
	
	delete var;
	delete[] vet;
}
