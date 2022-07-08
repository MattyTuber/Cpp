#include <iostream>

using namespace std;

struct stampa {
	
	int max;
	int min;	
	
};

void vettore (int *vet, int N);
struct stampa maxMin (int *vet, int N);

int main()
{
	int N;
	
	struct stampa massimoMinimo;
	
	cout << "Inserire dimensione vettore --> ";
	cin >> N;
	
	int vet [N];
	
	vettore (vet, N);
	
	massimoMinimo = maxMin (vet, N);
	
	cout << "Massimo --> " << massimoMinimo.max << endl;
	cout << "Minimo --> " << massimoMinimo.min;
}

void vettore (int *vet, int N)
{
	int i;
	
	for (i=0; i<N; i++){
		cout << "Inserire valore posizione " << i << " --> ";
		cin >> vet [i];
	}
}

struct stampa maxMin (int *vet, int N)
{
	struct stampa max_Min;
	
	int i;
	int massimo = vet [0];
	int minimo = vet [0];
	
	for (i=0; i<N; i++){
		if (vet [i] > massimo)
			massimo = vet [i];
		if (vet [i] < minimo)
			minimo = vet [i];
	}
	
	max_Min.max = massimo;
	max_Min.min = minimo;
	
	return max_Min;
}
