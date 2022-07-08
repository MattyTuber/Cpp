#include <stdio.h>
#include <stdlib.h>

void primo(){
	int i, j, dim, *vet;
	
	vet = (int*) malloc(sizeof(int));

	printf ("Inserire Dimensione Memoria --> ");
	scanf ("%d", &dim);
		
	for (i=0; i<dim; i++){
		printf("Inserire un numero --> ");
		scanf("%d", &vet[i]);
	}
			
	for (i=dim-1; i>=0; i--)
		printf("%d\t", vet [i]);
}

void secondo(){
	int *vet, i=0;
	
	vet = (int*) malloc(sizeof(int) * 2);
	
	while (true){
		printf ("Inserire un Numero --> ");
		scanf("%d", &vet [i]);
		
		vet = (int*) realloc (vet, sizeof(int) * 2);
		if (vet [i] == 0)
			break;
			
		i++;
	}
	
	for (i-=1; i>=0; i--)
		printf("%d\t", vet [i]);
}

void contorno(){
	int *vet, i=0;
	
	vet = (int*) malloc(15);
	
	while (true){
		printf ("Inserire un Numero --> ");
		scanf("%d", &vet [i]);
		
		vet = (int*) realloc (vet, sizeof(int) * 15 + 10);
		
		if (vet [i] == 0)
			break;
			
		i++;
	}
	
	for (i-=1; i>=0; i--)
		printf("%d\t", vet [i]);
}

int main()
{
	int opt;
	
	printf ("Inserire l'Opzione --> ");
	scanf ("%d", &opt);
	
	switch (opt){
		case 1:
			primo();
		break;
		
		case 2:
			secondo();
		break;
		
		case 3:
			contorno();
		break;
		
		default:
			printf("Errore!!");
		break;
	}
}
