#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define R 10
#define C 10

int main()
{
	FILE *fp;
	char path [128];
	float mat [R] [C];
	int c, r;
	srand(time(NULL));
	
	cout << "Inserire percorso file --> ";
	cin >> path;
	
	fp = fopen (path, "w");
	
	if (fp == NULL){
		cout << "Errore di lettura!!";
		
		exit (1);
	}
	
	for (int i = 0; i<R; i++){
		for (int j = 0; j<C; j++){
			mat [i] [j] = ((float)rand()/(float)(RAND_MAX)) * 2;
		}
	}
	
	for (int i = 0; i<R; i++){
		for (int j = 0; j<C; j++){
			fprintf (fp, "%.2f ", mat [i] [j]);
		}
		
		fputc ('\n', fp);
	}
}
