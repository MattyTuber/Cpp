#include <iostream>

using namespace std;

int main()
{
	FILE *fp;	

	int num, somma = 0, cont = 0;
	float media;
	char path [128];
	
	cout << "Inerire percorso file --> ";
	cin >> path;
	
	fp = fopen(path, "r");
	
	if (fp == NULL){
		cout << "Errore di lettura!!";
		
		exit(1);
	}
	
	while(!feof(fp)){
		fscanf (fp, "%d", &num);
		
		somma += num;
		cont++;
	}
	
	media = somma / cont;
	
	fclose (fp);
	
	cout << "Media --> " << media;
	
	return 0;
}
