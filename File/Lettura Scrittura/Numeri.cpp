#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	FILE *fp;
	char path [128], content;
	
	cout << "Inserire percorso file --> ";
	cin >> path;
	
	fp = fopen (path, "r");
	
	if (fp == NULL){
		cout << "Errore nella lettura!!";
		return (1);
	}
	
	content = fgetc (fp);
	
	while (!feof(fp)){
		cout << content;
		content = fgetc (fp);		
	}
	
	fclose(fp);
	
	fp = fopen (path, "w");
	
	if (fp == NULL){
		cout << "Errore nella scrittura!!";
		return (1);
	}
	
	int n, num;
	
	cout << "\nQuanti numeri vuoi inserire --> ";
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cout << "Inserire un numero --> ";
		cin >> num;
		
		fprintf (fp, "%d\t", num);
	}
	
	fclose (fp);
	
	return 0;
}
