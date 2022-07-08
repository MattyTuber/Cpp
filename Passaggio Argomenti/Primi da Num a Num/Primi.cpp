#include <iostream>
#include <cstdlib>

using namespace std;

void primo (int partenza, int num);

int main(int argc, char *argv[])
{
	cout << "Benvenuto nel programma " << argv[0] << endl;
	
	int num = 0, partenza = 0;
	
	//Controllo se ricevo tutti i parametri
	if(argc >= 2){
		partenza = atoi (argv [1]);
		//Se entra nell' if ho ricevuto tutti i parametri
		if (argc > 2){
			num = atoi (argv [2]);
		}
		//Mi manca il secondo parametro che ciedo in input
		else{
			cout << "Inserire arrivo --> ";
			cin >> num;
		}
	}
	//Non ho ricevuto nessun parametro
	else{
		cout << "Inserire un numero --> ";
		cin >> partenza;
		
		cout << "Inserire il numero di arrivo --> ";
		cin >> num;
	}
	
	primo (partenza, num);
	
	return 0;
}

void primo(int p, int n)
{
	int i, j, cont;
	
	for (i=p; i<=n; i++)
	{
		cont = 0;
		
		for (j=1; j<=n; j++)
		{
			if (i % j == 0)
				cont++;
		}
		if (cont == 2)
		{
			cout << i << "\t";
		}
	}
}
