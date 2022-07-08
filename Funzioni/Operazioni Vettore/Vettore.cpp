#include <iostream>

using namespace std;

void avarage (int *vettore, int dimensioni);
void multiply (int *vettore, int dimensioni);

int main()
{
	int N, i;
	
	cout << "Inserire dimensione vettore --> ";
	cin >> N;
	
	int vet [N];
	
	for (i=0; i<N; i++){
		cout << "Inserire un numero --> ";
		cin >> vet [i];
	}
	
	avarage (vet, N);
	multiply (vet, N);
}

void avarage (int *v, int N)
{
	int i, somma = 0;
	
	for (i=0; i<N; i++){
		somma += v [i];
	}
	
	cout << "Somma --> " << somma << endl;
	cout << "Media --> " << somma/N << endl;
}

void multiply (int *v, int N)
{
	int i, mul = 1;
	
	for (i=0; i<N; i++){
		mul = mul * v [i];
	}
	
	cout << "Moltiplicazione --> " << mul;
}
