#include <stdio.h>

int main()
{
	FILE *fp;
	
	int min, num;
	
	//Apro il file in lettura
	fp = fopen("Numeri.txt", "r");
	
	//Controllo per errori in lettura
	if (fp == NULL){
		printf("Errore di lettura!!");
		
		return 1;
	}
	
	//Salvo nella viariabile min il primo valore
	fscanf (fp, "%d", &min);
	
	//Ripeto fino a fine file
	while (!feof(fp)){
		fscanf (fp, "%d", &num);
		
		//Se il numero ottenuto è minore di min al momento risulta essere il più basso
		//quindi aggiorno la variabile min con il nuovo valore
		if (num < min)
			min = num;
	}
	
	//Stampo il valore
	printf ("Minimo --> %d", min);
	
	fclose (fp);
}
