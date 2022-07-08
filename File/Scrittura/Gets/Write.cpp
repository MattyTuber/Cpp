#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	FILE *fp;
	char path [128], text [255];
	
	cout << "Inserire percorso file --> ";
	cin >> path;
	getchar(); //Elimino il \n salvato in memoria
	
	fp = fopen (path, "w");
	
	if (fp == NULL){
		cout << "Errore nella scrittura!!";
		exit (1);
	}
	
	//Prende in input una frase
	cout << "Inserire il testo --> ";
	gets (text);
	fprintf(fp, "%s", text);
	
	fclose(fp);
	
	return 0;
}
