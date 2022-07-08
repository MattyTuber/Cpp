#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	FILE *fp, *sum;
	char path [128];
	
	int num1, num2;
	
	cout << "Inserire percorso file --> ";
	cin >> path;
	getchar(); //Elimino il \n salvato in memoria
	
	fp = fopen (path, "r");
	
	if (fp == NULL){
		cout << "Errore nella lettura!!";
		exit (1);
	}
	
	sum = fopen ("Somma.txt", "w");
	
	if (sum == NULL){
		cout << "Errore nella scrittura!!";
		exit (1);
	}
	
	while (!feof(fp)){
		fscanf (fp, "%d\t%d", &num1, &num2);
		
		fprintf (sum, "%d\n", num1 + num2);
	}
	
	fclose(fp);
	fclose(sum);
	
	return 0;
}
