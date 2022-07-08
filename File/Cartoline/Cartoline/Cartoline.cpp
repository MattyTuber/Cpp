/*Realizzare un programma in linguaggio C per registrare le cartoline scambiate tra un gruppo di amici
(massimo 20 amici).
L’elenco delle cartoline è memorizzato in un ﬁle di testo, composto da un numero imprecisato di linee,
ciascuna delle quali contiene tre elementi :
-il nome del mittente
- il nome del destinatario
- il nome della località da cui la cartolina è stata inviata.
I nomi degli amici e delle località sono da intendersi privi di spazi e lunghi al massimo 30 caratteri ciascuno.
Il programma riceve come primo parametro il nome del ﬁle di testo,
mentre il secondo parametro può essere la stringa new oppure la stringa find.
Il comando new richiede ulteriori tre parametri, corrispondenti ai nomi degli amici e della località e deve aggiungere
tali informazioni in coda al ﬁle.
Il programma deve segnalare con un messaggio errore l’eventuale tentativo di re - introdurre una cartolina identica ad una già esistente.
Il comando find è invece seguito da un solo ulteriore parametro corrispondente al nome di un amico.
In questo caso il programma deve stampare l’elenco degli amici che hanno spedito
cartoline all’amico specificato e le località corrispondenti.*/

/* Andreis     Alessia     4BIN    06/10/2021 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char parametro[6];
	char mittente[30];
	char destinatario[30];
	char localita[30];
	char nome_file[30];
	char nome_amico[30];
	char mittente1[30];
	char destinatario1[30];
	char localita1[30];
	int duplicato = 0;

	FILE* fp;

	printf("\ninserire new/find --> ");
	scanf("%s", &parametro);

	if (strcmp(parametro, "new")==0) {

		printf("\nInserire il nome del file --> ");
		scanf("%s", &nome_file);

		fp = fopen(nome_file, "r+");

		if (!fp) {
			printf("ERRORE CON L'APERTURA DEL FILE");
		}

		printf("\nInserire un mittente --> ");
		scanf("%s", &mittente1);

		printf("\nInserire un destinatario --> ");
		scanf("%s", &destinatario1);
		
		printf("\nInserire una localita --> ");
		scanf("%s", &localita1);
		 

		while (!feof(fp))
		{
			fscanf(fp, "%s ", &mittente);
			fscanf(fp, "%s ", &destinatario);
			fscanf(fp, "%s", &localita);


			if (strcmp (mittente1, mittente) == 0 and strcmp (destinatario1, destinatario) == 0 and strcmp (localita1, localita) == 0) {
				duplicato = 1;

			}
		}

		if (duplicato == 0) {

			fprintf(fp, "\n%s %s %s", mittente1, destinatario1, localita1);

		}

		fclose(fp);
	}
	else if (strcmp(parametro, "find")==0) {
		fp = fopen("Cartoline.txt", "r");

		if (!fp) {
			printf("ERRORE CON L'APERTURA DEL FILE");
		}

		printf("\nInserire il nome di un amico --> ");
		scanf("%s", &nome_amico);

		while (!feof(fp))
		{
			fscanf(fp, "%s ", &mittente);
			fscanf(fp, "%s ", &destinatario);
			fscanf(fp, "%s", &localita);

			if (strcmp(destinatario, nome_amico) == 0) {
				printf("\nStampare il mittente --> %s", mittente);
				printf("\nStampare la localita --> %s", localita);
				
			}
		}

		fclose(fp);
	}
	return 0;
	}
