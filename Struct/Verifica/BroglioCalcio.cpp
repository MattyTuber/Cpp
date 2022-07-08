#include <iostream>
#include <string.h>

using namespace std;

struct squadra{
	char nome [20];
	
	int punteggio;
	int giocatori;
	
	float saldo;
};

void input(struct squadra *list, int N);
void stampaMinori (struct squadra *list, int N);
int stampaVincitore (struct squadra *list, int N);
void aggiornamentoSaldo (struct squadra *list, int N, int mem);

int main()
{
	int N, memory;
	
	cout << "Inserire il numero di Squadre --> ";
	cin >> N;
	
	struct squadra elenco [N];
	
	input (elenco, N);
	stampaMinori (elenco, N);
	memory = stampaVincitore (elenco, N);
	aggiornamentoSaldo (elenco, N, memory);
	
	return 0;
}

void input(struct squadra *list, int N)
{
	int i;
	
	for (i=0; i<N; i++){
		getchar();
		
		cout << endl << "Inserire Nome Squadra --> ";
		gets (list[i].nome);
		
		cout << "Inserire Punteggio Squadra --> ";
		cin >> list[i].punteggio;
		
		cout << "Inserire Numero di Giocatori --> ";
		cin >> list[i].giocatori;
		
		list[i].saldo = list[i].giocatori * 7.5;
	}
}

void stampaMinori (struct squadra *list, int N)
{
	int i;
	
	cout << "\nSquadre con meno di 7 Player:\n";
	
	for (i=0; i<N; i++){
		if (list[i].giocatori < 7)
			cout << list[i].nome << endl;
	}
}

int stampaVincitore (struct squadra *list, int N)
{
	int i, mem, max;
	
	max = list[0].punteggio;
	
	cout << "\nSquadra in Testa:\n";
	
	for (i=0; i<N; i++){
		if (list[i].punteggio > max)
		{
			max = list[i].punteggio;
			
			mem = i;
		}	
	}
		
	cout << "Nome --> " << list[mem].nome << endl;

	cout << "Punteggio --> " << list[mem].punteggio << endl;

	cout << "Giocatori --> " << list[mem].giocatori << endl;
		
	cout << "Saldo --> " << list[mem].saldo;
	
	return mem;
}

void aggiornamentoSaldo (struct squadra *list, int N, int mem)
{
	int fp, i;
	
	cout  << "\nInserire Posizione del Vincitore del Premio Fair Play --> ";
	cin >> fp;
	
	for (i=0; i<N; i++){
		if (i != mem){
			list[i].saldo -= 25;
			list[mem].saldo += 25;
		}
		
		if (i != fp){
			list[i].saldo -= 5;
			list[fp].saldo += 5;
		}
	}
	
	cout << "Saldo di Tutte le Squadre:";
	
	for (i=0; i<N; i++)
		cout << "\n\n" << list[i].nome << " --> " << list[i].saldo;
}
