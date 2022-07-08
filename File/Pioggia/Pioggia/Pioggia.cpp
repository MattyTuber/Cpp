/* Scrivere un programma per salvare, giorno per giorno, su un file binario di nome pioggia.dat, la quantità in millimetri di pioggia caduta.
Successivamente leggere i dati registrati nel file Pioggia.dat e calcolare :
– la quantità di pioggia mediamente caduta al giorno;
– la quantità massima di pioggia caduta in un giorno;
– il periodo(numero di giorni consecutivi) più lungo di siccità.
Tali dati dovranno essere scritti in un nuovo file di testo il cui nome dovrà essere chiesto in input all'utente.
Strutturare il programma con un menù che permetta di :
1. inserire una nuova rilevazione
2. visualizzare i dati contenuti nel file pioggia.dat
3. visualizzare le statistiche contenute nel file di testo*/

#define	_CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(void) {
	FILE* fp;
	FILE* fd;

	int scelta, cont = 0;
	float rilev, n;
	char content, nome[128];

	fp = fopen("pioggia.dat", "w");

	printf("Inserire nome file di testo --> ");
	scanf("%s", &nome);

	fd = fopen(nome, "w+");
	
	if (fp == NULL) {
		perror("Errore in apertura del file");
		exit(1);
	}

	if (fd == NULL) {
		perror("Errore in apertura del file");
		exit(2);
	}

	while (true)
	{
		system("cls");
		printf("1. inserire una nuova rilevazione\n2. visualizzare i dati contenuti nel file pioggia.dat\n3. visualizzare le statistiche contenute nel file di testo\n4. uscire");
		printf("\nScelta --> ");
		scanf("%d", &scelta);

		switch (scelta)
		{
		case 1:
			printf("Inserire rilevazione --> ");
			scanf("%f", &rilev);
			cont++;

			fprintf(fp, "%.2f ", rilev);
			break;

		case 2:
			fclose(fp);
			fp = fopen("pioggia.dat", "r+");

			content = fgetc(fp);

			while (!feof(fp)) {
				printf("%c", content);
				content = fgetc(fp);
			}

			printf("\n");
			system("pause");
		break;

		case 3:
			float somma = 0, max = 0;
			int isZero = 0;
			fclose(fp);
			fp = fopen("pioggia.dat", "r+");

			while (!feof(fp)) {
				fscanf(fp, "%f ", &n);

				somma = somma + n;
				
				if (n > max)
					max = n;

				if (n == 0)
					isZero++;
			}

			fprintf(fd, "%f", somma / cont);
			fprintf(fd, "\n%f", max);
			fprintf(fd, "\n%d", isZero);

			fclose(fd);
			fd = fopen(nome, "r+");
			
			content = fgetc(fd);

			while (!feof(fd)) {
				printf("%c", content);
				content = fgetc(fd);
			}

			printf("\n");
			system("pause");
		break;

		case 4:
			fclose(fp);
			fclose(fd);
			return 0;
		break;

		default:
			printf("Scelta non presente");
		break;
		}
	}
}