#include<iostream>
#include <cstdio>

using namespace std;

#define MAX_TERREMOTI 10
#define ENERGIA_MAGNITUDO_ZERO 63
#define ENERGIA_MOLTIPLICATORE 31.623

void inserisci_terremoti(int *magnitudo_terremoti, int n);
int conta_pericolosi(int *terremoti, int l, int soglia);
void trova_magnitudo_max_min(int *terremoti, int l, int *max, int *min);
double calcola_energia(int magnitudo);

int main(){
	
	int magnitudo_soglia;
	int magnitudo_terremoti[MAX_TERREMOTI];
	int max_magnitudo, min_magnitudo;
	double energia;
	int num_terremoti_pericolosi, num_terremoti;
	
	cout << "Inserire la magnitudo soglia --> ";
	cin >> magnitudo_soglia;
	
	cout << "Inserire il numero di terremoti --> ";
	cin >> num_terremoti;
	
	cout << "Inserire la magnitudo dei diversi terremoti --> " << endl;
	inserisci_terremoti(magnitudo_terremoti, num_terremoti);
	
	
	num_terremoti_pericolosi = conta_pericolosi(magnitudo_terremoti, num_terremoti, magnitudo_soglia);
	printf("\nTra i terremoti inseriti, %d hanno magnitudo maggiore o uguale alla soglia e sono da considerare pericolosi\n", num_terremoti_pericolosi);
	
	trova_magnitudo_max_min(magnitudo_terremoti, num_terremoti, &max_magnitudo, &min_magnitudo);
	printf("Magnitudo massima inserita: %d\n", max_magnitudo);
	printf("Magnitudo minima inserita: %d\n", min_magnitudo);
		
	energia = calcola_energia(max_magnitudo);
	
	printf("L'energia liberata del terremoto di magnitudo massima %c di %lf kJ\n", 138, energia);
	
	return 0;
}

void inserisci_terremoti(int *vet, int n)
{
	int i;
	
	for (i=0; i<n; i++)
	{
		cout << "Inserire un valore --> ";
		cin >> vet [i];
	}
}

int conta_pericolosi (int *vet, int l, int soglia)
{
	int i;
	int cont=0;
	
	for (i=0; i<l; i++)
	{
		if (vet [i] >= soglia)
			cont++;
	}
	
	return cont;
}

void trova_magnitudo_max_min(int *vet, int l, int *max, int *min)
{
	int i;
	*max = vet [0];
	*min = vet [0];
	
	for (i=0; i<l; i++)
	{
		if (vet [i] > *max)
			*max = vet [i];
		else if (vet [i] < *min)
			*min = vet [i];
	}
}

double calcola_energia(int magnitudo)
{
	if (magnitudo <= 0)
		return ENERGIA_MAGNITUDO_ZERO;
	else
		return ENERGIA_MOLTIPLICATORE * calcola_energia (magnitudo-1);
}
