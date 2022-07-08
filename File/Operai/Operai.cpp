#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	FILE *fp;
	int n;
	char operaio [255];
	
	fp = fopen ("Operai.txt", "w");
	
	if (fp == NULL){
		cout << "Errore nella lettura!!";
		return (1);
	}
	
	cout << "Numero di operai --> ";
	cin >> n;
	getchar();
	
	for (int i = 0; i < n; i++){
		cout << "\nInserire Nome, Cognome, Ore di Lavoro --> ";
		gets (operaio);
		fprintf(fp, "%s\n", operaio);
	}
	
	fclose (fp);
	
	return 0;
}
