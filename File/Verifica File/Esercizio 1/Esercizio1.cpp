#include <stdio.h>

int main()
{
	FILE *fp;
	
	char ch, libro [128];
	
	//Apro il file in append in modo da aggiungere elementi in coda
	fp = fopen("List.txt", "a");
	
	//Controllo eventuali errori nella scrittura
	if (fp == NULL){
		printf("Errore di scrittura!!");
		
		//In caso di errore termino il programma
		return 1;
	}
	
	//Il ciclo si ripete all'infinito fino a quando non inserisco K
	while (true){
		printf("Inserire Libro --> ");
		gets (libro);
		fprintf(fp, "\n%s", libro);
		
		printf("K per terminare --> ");
		ch = getchar();
		getchar();
		
		if (ch == 'K')
			return 0;
	}
	
	//Chiudo il file
	fclose (fp);
}
