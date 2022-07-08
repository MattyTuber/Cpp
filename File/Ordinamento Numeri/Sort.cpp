#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	FILE *fp;
	char path [128];
	int N, i, j, temp, key;
	
	srand(time(NULL));

	fp = fopen ("Numeri.txt", "w");
	
	if (fp == NULL){
		cout << "Errore nella scrittura!!";
		exit (1);
	}
	
	cout << "Dimensione --> ";
	cin >> N;

	for (i = 0; i < N; ++i){
		fprintf (fp, "%d ", rand()%99+1);
	}
	
	fclose(fp);
	
	fp = fopen ("Numeri.txt", "r");
	
	if (fp == NULL){
		cout << "Errore nella lettura!!";
		exit (1);
	}
	
	i = 0;
	
	int vet [N];
	
	while(!feof(fp)){
		fscanf (fp, "%d", &vet [i]);
			
		i++;
	}
	
	for (j = 1; j < N; ++j)
	{
		key = vet[j];

		for (i = j-1; i>=0 && vet[i]>key; i--)
			vet[i+1] = vet[i];
		vet[i+1] = key;
	}
	
	fclose(fp);
	
	fp = fopen ("Sort.txt", "w");
	
	if (fp == NULL){
		cout << "Errore nella scrittura!!";
		exit (1);
	}
	
	for (i = 0; i < N; ++i)
		fprintf(fp, "%d ", vet[i]);

	return 0;
}
