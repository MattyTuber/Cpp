#include <iostream>
#include <cstdlib>

using namespace std;

double avarage(double mat[][100], int row, int col);

int main()
{
	int i, j;
   	int row1, row2, col1, col2;
   	double mat1 [100] [100], mat2 [100] [100];

   	cout << "Numero righe Matrice 1 --> ";
   	cin >> row1;
   
   	cout << "Numero colonne Matrice 1 --> ";
   	cin >> col1;
   
   	cout << "Numero righe Matrice 2 --> ";
   	cin >> row2;
   
   	cout << "Numero colonne Matrice 2 --> ";
   	cin >> col2;
   
	cout << "Input Matrice 1" << endl;
   	for (i=0; i<row1; i++)
	{
		for (j=0; j<col1; j++)
		{
			cout << "Inserire un numero --> ";
			cin >> mat1 [i] [j];
		}
	}

	cout << "Input Matrice 2" << endl;
   	for (i=0; i<row2; i++)
	{
		for (j=0; j<col2; j++)
		{
			cout << "Inserire un numero --> ";
			cin >> mat2 [i] [j];
		}
	}
	
	cout << "Media Matrice 1 --> " << avarage (mat1, row1, col1) << endl;
	cout << "Media Matrice 2 --> " << avarage (mat2, row2, col2);
	
   	return 0;
}

double avarage(double mat[][100], int row, int col)
{
   	float somma = 0;
   	int i, j;

   	for (i=0; i<row; i++)
      	for (j=0; j<col; j++)
       		somma += mat [i] [j];
   
   	return somma / (row * col);
}
