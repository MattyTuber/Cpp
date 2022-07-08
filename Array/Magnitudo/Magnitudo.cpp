#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, lim, s_1 = 0, s_2 = 0;
	float media_1, media_2, somma_1 = 0, somma_2 = 0;
	char e = 138;

	//Eseguo un ciclo che controlla l'input in modo che rientri nei criteri stabiliti
	do{
		cout << "Inserire il numero di terremoti --> ";
		cin >> N;
	}while (N>10);

	float vett[N];

	//Prendo in input il numero richiesto di valori
	for (i = 0; i < N; ++i)
	{
		cout << "Inserire la magnitudo --> ";
		cin >> vett[i];
	}

	cout << "Insrire un valore limite --> ";
	cin >> lim;

	//Controllo ciclicamente se il valore limite precedente inserito viene superato o meno
	for (i = 0; i < N; ++i)
	{
		
		//Nel caso in cui venga superato stampo l'id del terremoto e la sua magnitudo
		if (vett[i] >= lim)
		{
			cout << "Il terremoto " << i+1 << " " << e << " pericoloso (magnitudo " << vett[i] << ")" << endl;

			//Sommo tutti i valori e incremento un indice, mi servirà per la media
			somma_1 += vett[i];
			s_1++;
		}
		
		//In caso contrario sommo tutti i restanti valori e incremento un indice, mi servirà per la media
		else 
		{
			somma_2 += vett[i];
			s_2++;
		}
	}

	/*Eseguo un cast forzato (temporaneo) da int a float perchè un operazione tra due int restituisce in cout un int,
	facendo così restituisce in output un float*/
	media_1 = static_cast <float> (somma_1) / s_1;
	media_2 = static_cast <float> (somma_2) / s_2;

	cout << "Magnitudo media dei terremoti pericolosi --> " << media_1 << endl;
	cout << "Magnitudo media terremoti non pericolosi --> " << media_2;
	
	return 0;
}
