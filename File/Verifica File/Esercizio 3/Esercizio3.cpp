#include <stdio.h>

int main()
{
	FILE *fp, *fp2;
	
	char mod [128], plate [128], year [128], buffer [128];
	
	//Apro il primo file in lettura
	fp = fopen("Auto.txt", "r");
	
	//Controllo per eventuali errori
	if (fp == NULL){
		printf("Errore di lettura!!");
		
		return 1;
	}
	
	//Apro il secondo file in scrittura
	fp2 = fopen("Auto2.txt", "w");
	
	//Controllo eventuali errori
	if (fp2 == NULL){
		printf("Errore di scrittura!!");
		
		return 1;
	}
	
	
	//Il ciclo si ripete fino a che la stringa che prendo non ha valore nullo
	//buffer è una variabile che assume il valore di tutta la riga
	while (fgets (buffer, sizeof(buffer), fp) != NULL) {
		//Suddivido l'input da file in tre diverse variabili
        sscanf (buffer, "%s %s %s", &mod, &plate, &year);
		
		//Scrivo sul nuovo file solo la targa e l'anno
		fprintf (fp2, "%s %s\n", plate, year);
    }
	
	
	//Chiudo entrambe i file aperti
	fclose (fp);
	fclose (fp2);
}
