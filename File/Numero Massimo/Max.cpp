#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	FILE *fp;	

	int num = 0, max;
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
		
		if (num > max)
			max = num;
	}
	
	fclose (fp);
	
	cout << "Massimo --> " << max;
	
	return 0;
}
