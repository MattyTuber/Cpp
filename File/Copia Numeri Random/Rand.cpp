#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

#define LEN 500

int main()
{
	FILE *fp1, *fp2;
	
	char path [128], c;
	
	srand(time(NULL));
	
	cout << "Inerire percorso file --> ";
	cin >> path;
	
	fp1 = fopen(path, "w");
	
	if (fp1 == NULL){
		cout << "Errore di scrittura!!";
		
		exit(1);
	}
	
	for (int i = 0; i<LEN; i++){
		fprintf (fp1, "%d ", rand()%11);
	}
	
	fclose (fp1);
	
	fp1 = fopen(path, "r");
	
	if (fp1 == NULL){
		cout << "Errore di lettura!!";
		
		exit(1);
	}
	
	fp2 = fopen("Destination.txt", "w");
	
	if (fp2 == NULL){
		cout << "Errore di scrittura!!";
		
		exit(1);
	}
	
	c = fgetc (fp1);
	
	while (c != EOF){
		fputc (c, fp2);
		
		c = fgetc (fp1);
	}
	
	fclose (fp1);
	fclose (fp2);
	
	return 0;
}
