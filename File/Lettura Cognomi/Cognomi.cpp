#include <cstdio>
#include <iostream>

using namespace std;

int main ()
{
    FILE *fp;
	
	char nome[50], cognome[50], path [256], buffer [256];
    
    printf("Inserire percorso file --> ");
    scanf("%s", &path);
    getchar();
    
    fp = fopen(path,"r");
    
    if (fp == NULL){
		printf ("Errore nella lettura!!");
		return (1);
	}
    
    while (fgets (buffer, sizeof(buffer), fp) != NULL) {
        sscanf (buffer, "%s %s", &cognome, &nome);
    	printf ("Cognome --> %s\n", cognome);
    }
    
    fclose (fp);

    return 0;
}
