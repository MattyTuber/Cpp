#include <iostream>
#include <time.h>
#include <cstdlib>

#define SIZE 100

using namespace std;

void ins (int matrix[][SIZE], int row, int column);
void print (int matrix[][SIZE], int row, int column);

int main ()
{
    int mat[SIZE][SIZE];
    int row, col;

    cout << "Inserire le righe --> ";
    cin >> row;
    
    cout << "Inserire le colonne --> ";
    cin >> col;
    
	ins(mat, row, col);

    printf ("Matrice --> \n");
    print(mat, row, col);

    return 0;
}

void ins (int matrix[][SIZE], int row, int column)
{
    int i, j;
    
    srand(time(NULL));

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            matrix [i] [j] = rand()%50+1;
        }
    }
    
    for (i=0; i<row; i++)
    {
    	matrix[i][0] = 0;
    	matrix[i][column-1] = 0;
    	
    	for (j=0; j<column; j++)
		{
			matrix[0][j] = 0;
    		matrix[row-1][j] = 0;
		}
	}
}

void print (int matrix[][SIZE], int row, int column)
{
    int i;
    int j;

    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            printf("%-3d ", matrix[i][j]);
        }
        printf("\n");
    }
}
