#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp1, *fp2;
	
	char str [100];
	
	fp1 = fopen ("Source.txt", "r");
	
	if (fp1 == NULL){
		printf("Errore di Lettura!!");
		
		return (10);
	}
	
	fp2 = fopen ("Destination.txt", "w");
	
	if (fp2 == NULL){
		printf("Errore di Scrittura!!");
		
		return (20);
	}
	
	while (!feof(fp1)){
		fgets (str, 100, fp1);
		fputs (str, fp2);
	}
	
	fclose (fp1);
	fclose (fp2);
	
	printf("Copia effettuata con successo!!");
	
	return 0;
}
