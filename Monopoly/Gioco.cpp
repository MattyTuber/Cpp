#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

//Salvo le informazioni di ogni giocatore all'interno di una struct
struct player{
	char nome [50];
	int saldo;
	int posizione;
};

//Variabile Globale accessibile in tutte le funzioni
struct player giocatore [8];

//Inizializzo tutti i giocatori inserendo le informazioni in un'appostita struct
int inizializzaGiocatori ()
{
	int nGiocatori, i;
	
	cout << "Inserire Numero Giocatori --> ";
	cin >> nGiocatori;
	getchar();
	
	for (i=0; i<nGiocatori; i++){
		
		cout << "Inserire Nome Giocatore --> " << endl;
		gets(giocatore[i].nome);
		
		cout << "Saldo inizializzato a 1500" << endl;
		giocatore[i].saldo = 1500;
		
		giocatore[i].posizione = 0;
	}
	
	system("cls");
	
	return nGiocatori;
}

//Salvo le informazioni di ogni casella all'interno di una struct
struct places{
	string nome;
	string colore;
	int prezzo;
	int rendita [5];
	int costoCasa;
	int nCase;
	string proprietario;
};

//Variabile Globale accessibile in tutte le funzioni
struct places casella [40];

//Inserisco le informazioni di ogni casella nella struct
void inizializzaTabellone()
{
	//Posizione 0
	casella[0].nome = "Via";
	
	//Posizione 1
	casella[1].nome = "Vicolo Corto";
	casella[1].colore = "Rosa";
	casella[1].prezzo = 150;
	casella[1].rendita[0] = 5;
	casella[1].rendita[1] = 25;
	casella[1].rendita[2] = 75;
	casella[1].rendita[3] = 225;
	casella[1].rendita[4] = 400;
	casella[1].costoCasa = 125;
	casella[1].nCase = 0;
	casella[1].proprietario = "Invenduto";
	
	//Posizione 2
	casella[2].nome = "Probabilita'";
	
	//Posizione 3
	casella[3].nome = "Vicolo Stretto";
	casella[3].colore = "Rosa";
	casella[3].prezzo = 150;
	casella[3].rendita[0] = 10;
	casella[3].rendita[1] = 50;
	casella[3].rendita[2] = 150;
	casella[3].rendita[3] = 450;
	casella[3].rendita[4] = 800;
	casella[3].costoCasa = 125;
	casella[3].nCase = 0;
	casella[3].proprietario = "Invenduto";
	
	//Posizione 4
	casella[4].nome = "Tassa Patrimoniale";
	
	//Posizione 5
	casella[5].nome = "Stazione Sud";
	casella[5].prezzo = 480;
	casella[5].rendita[0] = 60;
	casella[5].proprietario = "Invenduto";
	
	//Posizione 6
	casella[6].nome = "Bastioni Gran Sasso";
	casella[6].colore = "Blu";
	casella[6].prezzo = 250;
	casella[6].rendita[0] = 15;
	casella[6].rendita[1] = 75;
	casella[6].rendita[2] = 225;
	casella[6].rendita[3] = 675;
	casella[6].rendita[4] = 1000;
	casella[6].costoCasa = 125;
	casella[6].nCase = 0;
	casella[6].proprietario = "Invenduto";
	
	//Posizione 7
	casella[7].nome = "Imprevisti";
	
	//Posizione 8
	casella[8].nome = "Viale Monterosa";
	casella[8].colore = "Blu";
	casella[8].prezzo = 250;
	casella[8].rendita[0] = 15;
	casella[8].rendita[1] = 75;
	casella[8].rendita[2] = 225;
	casella[8].rendita[3] = 675;
	casella[8].rendita[4] = 1000;
	casella[8].costoCasa = 125;
	casella[8].nCase = 0;
	casella[8].proprietario = "Invenduto";
	
	//Posizione 9
	casella[9].nome = "Viale Vesuvio";
	casella[9].colore = "Blu";
	casella[9].prezzo = 300;
	casella[9].rendita[0] = 20;
	casella[9].rendita[1] = 100;
	casella[9].rendita[2] = 250;
	casella[9].rendita[3] = 750;
	casella[9].rendita[4] = 1125;
	casella[9].costoCasa = 125;
	casella[9].nCase = 0;
	casella[9].proprietario = "Invenduto";
	
	//Posizione 10
	casella[10].nome = "Prigione - Transito";
	
	//Posizione 11
	casella[11].nome = "Via Accademia";
	casella[11].colore = "Arancione";
	casella[11].prezzo = 350;
	casella[11].rendita[0] = 25;
	casella[11].rendita[1] = 125;
	casella[11].rendita[2] = 375;
	casella[11].rendita[3] = 1125;
	casella[11].rendita[4] = 1550;
	casella[11].costoCasa = 250;
	casella[11].nCase = 0;
	casella[11].proprietario = "Invenduto";
	
	//Posizione 12
	casella[12].nome = "Societa' Elettrica";
	casella[12].prezzo = 375;
	casella[12].rendita[0] = 50;
	casella[12].proprietario = "Invenduto";
	
	//Posizione 13
	casella[13].nome = "Corso Ateneo";
	casella[13].colore = "Arancione";
	casella[13].prezzo = 350;
	casella[13].rendita[0] = 25;
	casella[13].rendita[1] = 125;
	casella[13].rendita[2] = 375;
	casella[13].rendita[3] = 1125;
	casella[13].rendita[4] = 1550;
	casella[13].costoCasa = 250;
	casella[13].nCase = 0;
	casella[13].proprietario = "Invenduto";
	
	//Posizione 14
	casella[14].nome = "Piazza Universita'";
	casella[14].colore = "Arancione";
	casella[14].prezzo = 400;
	casella[14].rendita[0] = 30;
	casella[14].rendita[1] = 150;
	casella[14].rendita[2] = 450;
	casella[14].rendita[3] = 1250;
	casella[14].rendita[4] = 1750;
	casella[14].costoCasa = 250;
	casella[14].nCase = 0;
	casella[14].proprietario = "Invenduto";
	
	//Posizione 15
	casella[15].nome = "Stazione Ovest";
	casella[15].prezzo = 480;
	casella[15].rendita[0] = 60;
	casella[15].proprietario = "Invenduto";
	
	//Posizione 16
	casella[16].nome = "Via Verdi";
	casella[16].colore = "Marrone";
	casella[16].prezzo = 450;
	casella[16].rendita[0] = 35;
	casella[16].rendita[1] = 175;
	casella[16].rendita[2] = 500;
	casella[16].rendita[3] = 1375;
	casella[16].rendita[4] = 1875;
	casella[16].costoCasa = 250;
	casella[16].nCase = 0;
	casella[16].proprietario = "Invenduto";
	
	//Posizione 17
	casella[17].nome = "Probabilita'";
	
	//Posizione 18
	casella[18].nome = "Corso Raffaello";
	casella[18].colore = "Marrone";
	casella[18].prezzo = 450;
	casella[18].rendita[0] = 35;
	casella[18].rendita[1] = 175;
	casella[18].rendita[2] = 500;
	casella[18].rendita[3] = 1375;
	casella[18].rendita[4] = 1875;
	casella[18].costoCasa = 250;
	casella[18].nCase = 0;
	casella[18].proprietario = "Invenduto";
	
	//Posizione 19
	casella[19].nome = "Piazza Dante";
	casella[19].colore = "Marrone";
	casella[19].prezzo = 500;
	casella[19].rendita[0] = 40;
	casella[19].rendita[1] = 200;
	casella[19].rendita[2] = 550;
	casella[19].rendita[3] = 1500;
	casella[19].rendita[4] = 2000;
	casella[19].costoCasa = 250;
	casella[19].nCase = 0;
	casella[19].proprietario = "Invenduto";
	
	//Posizione 20
	casella[20].nome = "Posteggio Gratuito";
	
	//Posizione 21
	casella[21].nome = "Via Marco Polo";
	casella[21].colore = "Rosso";
	casella[21].prezzo = 550;
	casella[21].rendita[0] = 45;
	casella[21].rendita[1] = 225;
	casella[21].rendita[2] = 625;
	casella[21].rendita[3] = 1750;
	casella[21].rendita[4] = 2200;
	casella[21].costoCasa = 375;
	casella[21].nCase = 0;
	casella[21].proprietario = "Invenduto";
	
	//Posizione 22
	casella[22].nome = "Imprevisti";
	
	//Posizione 23
	casella[23].nome = "Corso Magellano";
	casella[23].colore = "Rosso";
	casella[23].prezzo = 550;
	casella[23].rendita[0] = 45;
	casella[23].rendita[1] = 225;
	casella[23].rendita[2] = 625;
	casella[23].rendita[3] = 1750;
	casella[23].rendita[4] = 2200;
	casella[23].costoCasa = 375;
	casella[23].nCase = 0;
	casella[23].proprietario = "Invenduto";
	
	//Posizione 24
	casella[24].nome = "Largo Colombo";
	casella[24].colore = "Rosso";
	casella[24].prezzo = 600;
	casella[24].rendita[0] = 50;
	casella[24].rendita[1] = 250;
	casella[24].rendita[2] = 750;
	casella[24].rendita[3] = 1875;
	casella[24].rendita[4] = 2250;
	casella[24].costoCasa = 375;
	casella[24].nCase = 0;
	casella[24].proprietario = "Invenduto";
	
	//Posizione 25
	casella[25].nome = "Stazione Nord";
	casella[25].prezzo = 480;
	casella[25].rendita[0] = 60;
	casella[25].proprietario = "Invenduto";
	
	//Posizione 26
	casella[26].nome = "Viale Costantino";
	casella[26].colore = "Giallo";
	casella[26].prezzo = 650;
	casella[26].rendita[0] = 55;
	casella[26].rendita[1] = 275;
	casella[26].rendita[2] = 825;
	casella[26].rendita[3] = 2000;
	casella[26].rendita[4] = 2500;
	casella[26].costoCasa = 375;
	casella[26].nCase = 0;
	casella[26].proprietario = "Invenduto";
	
	//Posizione 27
	casella[27].nome = "Viale Traiano";
	casella[27].colore = "Giallo";
	casella[27].prezzo = 650;
	casella[27].rendita[0] = 55;
	casella[27].rendita[1] = 275;
	casella[27].rendita[2] = 825;
	casella[27].rendita[3] = 2000;
	casella[27].rendita[4] = 2500;
	casella[27].costoCasa = 375;
	casella[27].nCase = 0;
	casella[27].proprietario = "Invenduto";
	
	//Posizione 28
	casella[28].nome = "Societa' Acqua Potabile";
	casella[28].prezzo = 375;
	casella[28].rendita[0] = 50;
	casella[28].proprietario = "Invenduto";
	
	//Posizione 29
	casella[29].nome = "Piazza Giulio cesare";
	casella[29].colore = "Giallo";
	casella[29].prezzo = 700;
	casella[29].rendita[0] = 60;
	casella[29].rendita[1] = 300;
	casella[29].rendita[2] = 900;
	casella[29].rendita[3] = 2125;
	casella[29].rendita[4] = 2625;
	casella[29].costoCasa = 375;
	casella[29].nCase = 0;
	casella[29].proprietario = "Invenduto";
	
	//Posizione 30
	casella[30].nome = "Prigione";
	
	//Posizione 31
	casella[31].nome = "Via Roma";
	casella[31].colore = "Verde";
	casella[31].prezzo = 750;
	casella[31].rendita[0] = 65;
	casella[31].rendita[1] = 325;
	casella[31].rendita[2] = 1000;
	casella[31].rendita[3] = 2250;
	casella[31].rendita[4] = 2750;
	casella[31].costoCasa = 500;
	casella[31].nCase = 0;
	casella[31].proprietario = "Invenduto";
	
	//Posizione 32
	casella[32].nome = "Corso Impero";
	casella[32].colore = "Verde";
	casella[32].prezzo = 750;
	casella[32].rendita[0] = 65;
	casella[32].rendita[1] = 325;
	casella[32].rendita[2] = 1000;
	casella[32].rendita[3] = 2250;
	casella[32].rendita[4] = 2750;
	casella[32].costoCasa = 500;
	casella[32].nCase = 0;
	casella[32].proprietario = "Invenduto";
	
	//Posizione 33
	casella[33].nome = "Probabilita'";
	
	//Posizione 34
	casella[34].nome = "Largo Augusto";
	casella[34].colore = "Verde";
	casella[34].prezzo = 800;
	casella[34].rendita[0] = 70;
	casella[34].rendita[1] = 375;
	casella[34].rendita[2] = 1125;
	casella[34].rendita[3] = 2500;
	casella[34].rendita[4] = 3000;
	casella[34].costoCasa = 500;
	casella[34].nCase = 0;
	casella[34].proprietario = "Invenduto";	
	
	//Posizione 35
	casella[35].nome = "Stazione Est";
	casella[35].prezzo = 480;
	casella[35].rendita[0] = 60;
	casella[35].proprietario = "Invenduto";
	
	//Posizione 36
	casella[36].nome = "Imprevisti";
	
	//Posizione 37
	casella[37].nome = "Viale Dei Giardini";
	casella[37].colore = "Viola";
	casella[37].prezzo = 900;
	casella[37].rendita[0] = 90;
	casella[37].rendita[1] = 500;
	casella[37].rendita[2] = 1250;
	casella[37].rendita[3] = 2750;
	casella[37].rendita[4] = 3250;
	casella[37].costoCasa = 500;
	casella[37].nCase = 0;
	casella[37].proprietario = "Invenduto";
	
	//Posizione 38
	casella[38].nome = "Tassa del Lusso";
	
	//Posizione 39
	casella[39].nome = "Parco Della Vittoria";
	casella[39].colore = "Viola";
	casella[39].prezzo = 1000;
	casella[39].rendita[0] = 125;
	casella[39].rendita[1] = 500;
	casella[39].rendita[2] = 1500;
	casella[39].rendita[3] = 3500;
	casella[39].rendita[4] = 4250;
	casella[39].costoCasa = 500;
	casella[39].nCase = 0;
	casella[39].proprietario = "Invenduto";
}

//In modo casuale lancio due dadi e ne stampo il risultato che verrà anche ritornato al main
int lancioDadi ()
{
	int dado1, dado2, totale;

	printf("\n========== Lancio dei Dadi ==========\n");
	getchar();
	
	dado1 = (rand() % 6) + 1;
	dado2 = (rand() % 6) + 1;
	
	totale = dado1 + dado2;

	printf(" * Lancio: %d + %d = %d\n", dado1, dado2, totale);
	
	return totale;
}

//Mi muovo sul tabellone di quanto indicato dai dadi
int movimento (int posAttuale, int dadi)
{
	int nuovaPos = posAttuale + dadi;
	
	//Controllo se il giocatore è passato dal via
	if (nuovaPos >= 40){
		nuovaPos -= 40;
		
		return nuovaPos;
	}
}

void compraProp (int i)
{
	//Si può acquistare una proprietà solo se il saldo è superiore all'importo
	if (giocatore[i].saldo > casella[giocatore[i].posizione].prezzo){
		
		giocatore[i].saldo -= casella[giocatore[i].posizione].prezzo;
		casella[giocatore[i].posizione].proprietario = giocatore[i].nome;
		
		cout << "\nAcquisto Completato\n";
		cout << "SALDO: " << giocatore[i].saldo << "\n";
	}
	else
		cout << "\nDenaro Insufficiente. Impossibile completare l'acquisto!!\n";
	
	getchar();
}

void compraCasa (int i)
{
	int j, cont = 0, color = 0;
	
	//Conto il numero di proprietà del colore della casella dove è il Player
	for (j=0; j<40; j++){
		if (casella[giocatore[i].posizione].colore == casella[j].colore)
			cont++;
	}
	
	//Conto il numero di proprietà di colore X che il player possiede
	for (j=0; j<40; j++){
		if (casella[j].proprietario == giocatore[i].nome)
			if (casella[giocatore[i].posizione].colore == casella[j].colore)
				color++;
	}
	
	//Verifico se il numero di proprietà di colore X corrisponde al numero di proprietà del player di quel colore
	if (cont == color){
		//Acquisto la casa
		giocatore[i].saldo -= casella[giocatore[i].posizione].costoCasa;
		//Per chiarezza non utilizzo ++
		casella[giocatore[i].posizione].nCase += 1;
		
		cout << "\nCasa Acquistata con successo!!\n";
		cout << "SALDO: " << giocatore[i].saldo << "\n";
	}else
		cout << "\nNon disponi di abbastanza caselle di colore " << casella[giocatore[i].posizione].colore << " per acquistare una Casa\n";
}

int turno (int i, int nGiocatori, int *contBancarotta, int *turni)
{	
	printf("\n================================= Turno %3d =================================\n", *turni);
	printf("\n========== Giocatore %d - %s ==========\n", i + 1, giocatore[i].nome);
	printf(" * SALDO   : %d euro\n", giocatore[i].saldo);
	printf(" * POSIZIONE : Casella %d - %s\n", giocatore[i].posizione, casella[giocatore[i].posizione].nome.c_str());
	printf("\n=======================================\n");
	
	int tempPos = giocatore[i].posizione;
	
	giocatore[i].posizione = movimento(giocatore[i].posizione, lancioDadi());
	
	//Se il giocatore passa dal via riceve 200 euro
	if (giocatore[i].posizione == 0 || giocatore[i].posizione < tempPos)
	{
		cout << "\n Sei passato per il VIA. Ricevi 200 euro\n";
		giocatore[i].saldo += 200;
		cout << "\nSALDO ATTUALE : " << giocatore[i].saldo << " euro\n";
	}
	
	printf("\nPOSIZIONE ATTUALE = Casella %d - %s\n", giocatore[i].posizione, casella[giocatore[i].posizione].nome.c_str());
	
	/*
	 *Stampo, come se fosse una schedina del Monopoly, le informazioni della casella.
	 *Controllo se la casella ha un prezzo diverso da 0 ossia se è una proprietà acquistabile
	*/ 
	if (casella[giocatore[i].posizione].prezzo != 0)
	{
		printf("\n             PROPRIETA'          \n");
		printf(" __________________________________\n");
		printf(" |                                |\n");
		printf(" | %-30.30s |   * PROPRIETARIO : %s\n", casella[giocatore[i].posizione].nome.c_str(), casella[giocatore[i].posizione].proprietario.c_str());
		printf(" |                                |   * CASE         : %d\n", casella[giocatore[i].posizione].nCase);
		printf(" |  COLORE %-11.11s PREZZO %1d |\n", casella[giocatore[i].posizione].colore.c_str(), casella[giocatore[i].posizione].prezzo, casella[giocatore[i].posizione].nCase);
		printf(" | ------------------------------ |\n");
		printf(" |             RENDITA            |\n");
		printf(" |   Terreno             %4d     |\n", casella[giocatore[i].posizione].rendita[0]);
		printf(" |                                |\n");
		printf(" |   Stesso Colore       %4d     |\n", casella[giocatore[i].posizione].rendita[0] * 2);
		printf(" |                                |\n");
		printf(" |   Con 1 Casa          %4d     |\n", casella[giocatore[i].posizione].rendita[1]);
		printf(" |                                |\n");
		printf(" |   Con 2 Case          %4d     |\n", casella[giocatore[i].posizione].rendita[2]);
		printf(" |                                |\n");
		printf(" |   Con 3 Case          %4d     |\n", casella[giocatore[i].posizione].rendita[3]);
		printf(" |                                |\n");
		printf(" |   Con 4 Case          %4d     |\n", casella[giocatore[i].posizione].rendita[4]);
		printf(" | ------------------------------ |\n");
		printf(" |     Prezzo di ogni Casa %4d   |\n", casella[giocatore[i].posizione].costoCasa);
		printf(" | ------------------------------ |\n");
		printf(" |                                |\n");
		printf(" __________________________________\n");
	}
	else
	{
		switch (giocatore[i].posizione){
			//Entrati in prigione si esce pagando 125€
			case 10:
				cout << "\nTransiti in Prigione!!\n";
				giocatore[i].posizione = 30;
			case 30:
				cout << "\nSei in prigione - Paghi 125 euro per uscire\n";
				giocatore[i].saldo -= 125;
				cout << "\nSALDO: " << giocatore[i].saldo << " euro\n";
			break;
			
			//Imprevisti
			case 7:
			case 22:
			case 36:
				cout << "\nPesca una carta Imprevisti!!\n";
			break;
			
			//Probabilità
			case 2:
			case 17:
			case 33:
				cout << "\nPesca una carta Probabilita'!!\n";
			break;
			
			//Tassa Patrimoniale
			case 4:
				cout << "\nDevi pagare 500 euro di Tassa Patrimoniale\n";
				giocatore[i].saldo -= 500;
				cout << "\nSALDO: " << giocatore[i].saldo << " euro\n";
			break;
			
			//Tassa del Lusso
			case 38:
				cout << "\nDevi pagare 250 euro di Tassa del Lusso\n";
				giocatore[i].saldo -= 250;
				cout << "\nSALDO: " << giocatore[i].saldo << " euro\n";
			break;
		}
	}
	
	char risp;
	int j;
	
	if (casella[giocatore[i].posizione].proprietario == "Invenduto"){
		cout << "Vuoi comprare la proprieta'? Y/N\n";
		cin >> risp;
		
		if (risp == 'Y')
			compraProp(i);
	
	} else if (casella[giocatore[i].posizione].proprietario == giocatore[i].nome && casella[giocatore[i].posizione].costoCasa != 0){
		cout << "Vuoi comprare una casa? Y/N\n";
		cin >> risp;
		
		if (risp == 'Y')
			compraCasa(i);
	} else{ //Il giocatore deve pagare il proprietario del terreno
		//Il saldo del giocatore diminuisce in base alla rendita rispetto al numero di case
		//Controllo la rendita del giocatore nella posizione del vettore corrispondente al numero di case
		giocatore[i].saldo -= casella[giocatore[i].posizione].rendita[casella[giocatore[i].posizione].nCase];
		//Inceremento il saldo del proprietario
		for (j=0; j<nGiocatori; j++){
			//Controllo a quale giocatore appartiene la casella
			if (casella[giocatore[i].posizione].proprietario == giocatore[j].nome){
				//Verso il saldo al proprietario
				giocatore[j].saldo += casella[giocatore[i].posizione].rendita[casella[giocatore[i].posizione].nCase];
				
				break;
			}
		}
	}
	
	getchar();
	system ("cls");
}

int main()
{
	srand(time(NULL));
	
	int nGiocatori = inizializzaGiocatori();
	
	int i, turni = 1, contBancarotta = 0;
	
	inizializzaTabellone();
	
	do{
		for (i=0; i<nGiocatori; i++){
			turno(i, nGiocatori, &contBancarotta, &turni);
		}
		
		turni++;
	} while(giocatore[i].saldo < 10000 || turni != 999);
	
	if (turni != 999)
		//Si vince la partita arrivati a 10k euro
		cout << "\nCongratulazioni " << giocatore[i].nome << " hai appena vinto la partita!!";
	else
		cout << "\nLa partita e' terminata per un eccessivo numero di turni";
	
	getchar();
	
	return 0;
}
