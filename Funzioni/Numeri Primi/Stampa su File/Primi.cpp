#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void primo (int num, FILE *fp);

int main()
{
	FILE * fp;
	
	fp = fopen ("Primi.txt", "w+");
	
	int num;
	
	cout << "Inserire il numero massimo --> ";
	cin >> num;
	
	primo (num, fp);
	
	fclose(fp);
	
	return 0;
}

void primo(int n, FILE *fp)
{
	int i, j, cont;
	
	for (i=1; i<=n; i++)
	{
		cont = 0;
		
		for (j=1; j<=n; j++)
		{
			if (i % j == 0)
				cont++;
		}
		if (cont == 2)
		{
			fprintf(fp, "%d\t", i);
		}
	}
}
