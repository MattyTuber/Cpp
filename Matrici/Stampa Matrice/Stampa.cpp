#include <iostream>
#include <stdio.h>

#define NC 3
#define NR 3

using namespace std;

int main()
{
	int matrice[NR][NC] = {{2, 4, 3},
 						   {2, 1, 5},
 						   {5, 9, 8}};

 	for (int i = 0; i < 3; ++i)
 	{
 		for (int j = 0; j < 3; ++j)
 		{
 			cout << matrice[i][j] << "\t";
 		}

 		cout << endl;
 	}   
 						   
	return 0;
}