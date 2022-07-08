/*Leggere una matrice da tastiera
  stampare l'indice delle righe che finiscono con un numero dispari
  calcolare la media di ogni riga e salvarla in un vettore
  calcolarela media della colonna e salvarla in un vettore*/

#include <iostream>

using namespace std;

int main()
{
	int i, j, NR, NC, somma;
	float media;

	cout << "Numero di righe --> ";
	cin >> NR;

	cout << "Numero di colonne --> ";
	cin >> NC;

	int mat [NR] [NC];
	float vett_R [NC], vett_C [NR];

	//Input Matrice
	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			cout << "Inserire un valore --> ";
			cin >> mat [i] [j];
		}	
	}
	
	cout << endl;
	
	//Output Matrice
	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			cout << mat [i] [j] << "\t";
		}
		
		cout << "\n\n\n";
	}

	//Stampa indice riga
	for (i = 0; i < NR; ++i)
	{
		if ((mat [i] [NC - 1] % 2) != 0)
			cout << "La riga con indice " << i << " termina con un numero dispari" << endl;
		else
			cout << "La riga con indice " << i << " termina con un numero pari" << endl;
	}

	//Media della riga
	for (i = 0; i < NR; ++i)
	{
		somma = 0;
		
		for (j = 0; j < NC; ++j)
		{
			somma += mat [i] [j];
		}

		vett_R [i] = static_cast <float> (somma) / NC;
	}

	//Media della colonna
	for (i = 0; i < NC; ++i)
	{
		
		somma = 0;

		for (j = 0; j < NR; ++j)
		{
			somma += mat [j] [i];
		}

		vett_C [i] = static_cast <float> (somma) / NR;
	}
	
	cout << endl;

	//Stampa media Righe
	for (i = 0; i < NR; ++i)
	{
		cout << "Media Riga " << i+1 << " --> " << vett_R [i] << endl;
	}

	//Stampa media colonne
	for (i = 0; i < NC; ++i)
	{
		cout << "Media Colonna " << i+1 << " --> " << vett_C [i] << endl;
	}

	somma = 0;

	//Media Matrice
	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			somma += mat [i] [j];
		}
	}

	media = static_cast <float> (somma) / (NR * NC);

	cout << "Media della matrice --> " << media << endl;

	somma = 0;


	//Media tutte le righe
	for (i = 0; i < NR; ++i)
	{
		somma += vett_R [i];
	}

	media = static_cast <float> (somma) / NR;

	cout << "Media tra le varie righe --> " << media << endl;

	//Media tutte le colonne
	for (i = 0; i < NC; ++i)
	{
		somma += vett_C [i];
	}

	media = static_cast <float> (somma) / NC;

	cout << "Media tra le varie colonne --> " << media << endl;
	
	return 0;
}