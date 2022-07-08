#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAX 256

void genera (int matrice [] [MAX], int righe, int colonne);

void print (int matrice [] [MAX], int righe, int colonne);

int somma (int matrice [] [MAX], int righe, int colonne);

double moltiplica (int matrice [] [MAX], int righe, int colonne);

int main()
{
	int mat [MAX] [MAX];
	
	int righe, colonne;
	
	cout << "Inserire il numero di righe --> ";
	cin >> righe;
	
	cout << "Inserire il numero di colonne --> ";
	cin >> colonne;
	
	mat [righe] [colonne];
	
	genera (mat, righe, colonne);
	
	print (mat, righe, colonne);
	
	cout << "Somma --> " << somma (mat, righe, colonne) << endl;
	
	cout << "Moltiplicazione --> " << moltiplica (mat, righe, colonne) << endl;
	
	return 0;
}

void genera (int mat [] [MAX], int r, int c)
{
	srand (time(NULL));
	
	int i, j;
	
	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
			mat [i] [j] = rand()%10+1;
		}
	}
}

void print (int mat [] [MAX], int r, int c)
{	
	int i, j;
	
	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
			cout << mat [i] [j] << "\t";
		}
		
		cout << "\n\n";
	}
}

int somma (int mat [] [MAX], int r, int c)
{
	
	int i, j;
	
	int somma = 0;
	
	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
			somma += mat [i] [j];
		}
	}
	
	return somma;
}

double moltiplica (int mat [] [MAX], int r, int c)
{
	
	int i, j;
	
	double mol = 1;
	
	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
			mol = mol * mat [i] [j];
		}
	}
	
	return mol;
}
