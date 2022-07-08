/*scrivere un programma che generi un vettore randomicamente
  dopo di che richieda in input un valore che se non è presente
  nel vettore stamperà "valore non Trovato", se è presente ordinerà in senso crescente
  il vettore fino a quel numero, quelli successivi saranno ordinati in senso decrescente*/
  
/*Ordino poi controllo tutto il vettore fino al valore che ho inserito per controllare se è presente,
  se il valore verrà trovato ordino come richiesto altrimenti interrompo direttamente il programma*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, j, key, num, mem, temp;
	
	bool found = false;
	
	srand(time(NULL));

	cout << "Inserire il numero di valori --> ";
	cin >> N;

	int vet [N];

	for (i = 0; i < N; ++i)
	{
		vet [i] = rand()%99+1; 
	}
	
	//Ordino il vettore
	for (j = 1; j < N; ++j)
	{
		key = vet[j];
		
		for (i = j-1; i>=0 && vet[i]>key; i--)
			vet[i+1] = vet[i];
		
		vet[i+1] = key;
	}

	for (i = 0; i < N; ++i)
	{
		cout << vet [i] << "\t";
	}

	cout << endl;

	cout << "Inserie un numero --> ";
	cin >> num;

	//Scansiono il vttore per trovare il mio numero
	for (i=0; i<N && vet[i]<=num; i++)
	{
		if (vet[i] == num)
		{
			mem = i;
			
			found = true;
		}

	}
	
	//In caso in cui il valore non venga trovato chiudo il programma	
	if (found == false)
	{
		cout << "Non Trovato";
			
		return 0;
	}
	
	//Riordino in senso decrescente dal valore successivo a quello inserito
	for (i = 1; i < (N - mem)/2; ++i)
	{
		temp = vet [mem + i];

		vet [mem + i] = vet [N - i];

		vet [N - i] = temp;
	}

	for (i = 0; i < N; ++i)
	{
		cout << vet [i] << "\t";
	}

	return 0;
}

/*Prendo il vettore verifico, scorro, salvo in due vettori la parte prima e poi la parte dopo, 
minori ordinati in senso crescente, maggiori ordinati in senso decrescente,
li riporto tutti in un unico vettore e li stampo*/

/*Cerco e nel frattempo conto i valori <= a quello inserito, quando lo ordino modifico
l'algoritmo per scrivere in ordine crescente fino a quel valore e decrescente l'inverso*/

/*Mia soluzione --> ordino poi faccio ricerca binaria, i valori <= a quello inserito li tengo così,
gli altri li ribalto facendo scambi con una variabile temporanea*/

