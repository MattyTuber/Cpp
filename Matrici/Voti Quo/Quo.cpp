#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, val;

	//Eseguo un ciclo che controlla l'input in modo che rientri nei criteri stabiliti
	do{
		cout << "Inserire il numero di verifiche --> ";
		cin >> N;
	}while(N>10);

	//La matrice avrà un numero costante di colonne perchè il numero di persone rimane costantemente 3
	int mat [N] [3];

	//Prendo in input i voti dei tre nipoti
	for (i = 0; i < N; ++i)
	{
			cout << "Inserire il voto di Qui nella verifica " << i+1 << " --> ";
			cin >> mat [i] [0];

			cout << "Inserire il voto di Quo nella verifica " << i+1 << " --> ";
			cin >> mat [i] [1];

			cout << "Inserire il voto di Qua nella verifica " << i+1 << " --> ";
			cin >> mat [i] [2];
			
			cout << endl;
	}

	cout << "Inserire un voto da monitorare --> ";
	cin >> val;

	cout << "Verifiche in cui Quo ha preso " << val << ": " << endl;

	//Controllo in quali verifiche il voto corrisponde a quello inserito
	for (i = 0; i < N; ++i)
	{
		if (mat [i] [1] == val)
		{
			cout << "Verifica " << i+1 << endl;
		}
	}

	return 0;
}
