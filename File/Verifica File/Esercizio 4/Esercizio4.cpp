#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *fp, *fp2;
	
	srand(time(NULL));
	
	int num1, num2;
	char buffer [128];
	
	//Apro il primo file in lettura
	fp = fopen("Coord2D.txt", "r");
	
	//Controllo per eventuali errori
	if (fp == NULL){
		printf("Errore di lettura!!");
		
		return 1;
	}
	
	//Apro il secondo file in scrittura
	fp2 = fopen("Coord3D.txt", "w");
	
	//Controllo per eventuali errori
	if (fp2 == NULL){
		printf("Errore di scrittura!!");
		
		return 1;
	}
	
	//Il ciclo si ripete fino a che la stringa che prendo non ha valore nullo
	//buffer è una variabile che assume il valore di tutta la riga
	while (fgets (buffer, sizeof(buffer), fp) != NULL) {
		//Prendo in input da file le prime due colonne suddividendole
        sscanf (buffer, "%d %d", &num1, &num2);
		
		//Stampo sul nuovo file i due valori sopra acquisiti a cui aggingo una terza colonna
		fprintf(fp2, "%d ", num1);
		fprintf(fp2, "%d ", num2);
		//Aggiungo la terza dimensione con un valore decimale compreso tra 0 e 1
		fprintf(fp2, "%f\n", (double) rand()/RAND_MAX);
    }
	
	//Chiudo i file
	fclose (fp);
	fclose (fp2);
}
