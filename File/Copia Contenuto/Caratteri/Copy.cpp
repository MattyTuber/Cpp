#include <stdio.h>

int main()
{
	FILE *fp1, *fp2;
	
	char c;
	
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
	
	c = fgetc (fp1);
	
	while (c != EOF){
		fputc (c, fp2);
		
		c = fgetc(fp1);
	}
	
	fclose (fp1);
	fclose (fp2);
	
	printf("Copia effettuata con successo!!");
	
	return 0;
}
