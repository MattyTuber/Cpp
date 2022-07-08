#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	FILE *fp;
	char path [128], ch;
	
	cout << "Inserire percorso file --> ";
	cin >> path;
	getchar(); //Elimino il \n salvato in memoria
	
	fp = fopen (path, "wt");
	
	if (fp == NULL){
		cout << "Errore nella scrittura!!";
		exit (1);
	}
	
	//Prende in input una frase
	cout << "Inserire il testo --> " << endl;
	
	do {
		ch = getchar();
		fputc(ch, fp);
	} while (ch != '0');
	
	fclose(fp);
	
	return 0;
}
