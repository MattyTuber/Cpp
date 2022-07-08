/* Alessia Andreis 4 BIN 22/09/2021 */

/*Scrivi un programma che genera un numero random(compreso tra 100 e 200) di numeri interi e li salva su un file.
Tali numeri vengono poi ripresi da una funzione che li ordina in due nuovi file, una volta in modo crescente e l’altra in modo decrescente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crescente(FILE* fp, FILE* incr, int *vettore, int numero) {
	int i, j, temp;
	
	for (i = 1; i < numero; i++) {
		temp = vettore[i];
		j = i - 1;
		while (j >= 0 && vettore[j] > temp) {
			vettore[j + 1] = vettore[j];
			j--;
		}
		vettore[j + 1] = temp;
	}

	for (i = 0; i < numero; i++)
	{
		fprintf(incr, "%d ", vettore[i]);
	}
}

void decrescente(FILE* fp, FILE* decr, int* vettore, int numero) {
	int i, j, temp;

	for (i = 1; i < numero; i++) {
		temp = vettore[i];
		j = i - 1;
		while (j >= 0 && vettore[j] > temp) {
			vettore[j + 1] = vettore[j];
			j--;
		}
		vettore[j + 1] = temp;
	}

	for (i = 0; i < numero; i++)
	{
		fprintf(decr, "%d ", vettore[numero - i - 1]);
	}
}

int main()
{
	srand(time(NULL));

	FILE* fp;
	FILE* incr;
	FILE* decr;

	int numero, i, temp, j;

	numero = rand()%100 + 101;

	int vettore [200];

	fp = fopen("random.txt", "w");

	if (!fp) {
		printf("Errore di apertura!!!");

		return 19;
	}

	for (i=0; i<numero; i++)
	{
		fprintf(fp, "%d ", rand());
	}

	fclose(fp);

	fp = fopen("random.txt", "r");
	incr = fopen("increasing.txt", "w");
	decr = fopen("decreasing.txt", "w");

	if (!fp || !incr || !decr) {
		printf("Errore con i file!!!");
		return 12;
	}

	for (i = 0; i < numero; i++)
	{
		fscanf(fp, "%d ", &vettore[i]);
	}

	crescente(fp, incr, vettore, numero);
	decrescente(fp, decr, vettore, numero);

	fclose(fp);
	fclose(incr);
	fclose(decr);

	return 0;
}
