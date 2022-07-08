#include <cstdio>

int main()
{
    char str[256], path[128];
    FILE *fp;
    
    printf("Inserire percorso file --> ");
    scanf("%s", &path);
    getchar();
    
    fp = fopen(path,"w");
    
    if (fp == NULL){
		printf ("Errore nella scrittura!!");
		return (1);
	}
	
	printf("Inserire una stringa --> ");
	scanf("%c", &str);
	
	fputs(str, fp);
    
    fclose(fp);
    return 0;
}
