#include <stdio.h>
#include <cstdlib>
#include <ctime>

int main()
{
   	int i;
   	char str[100];
   	int crypt [100];
   	
   	srand(time(NULL));

   	printf("Inserire una stringa --> ");
   	gets(str);
  	
  	for (i = 0; i < 100; ++i)
	{
		crypt[i] = rand()%126+1;
	}
	 
	//Creare un programma permetta di decriptare il codice senza che venga necessariamente implementato nello stesso
	for(i = 0; (i < 100 && str[i] != '\0'); i++)
    	str[i] = str[i] + crypt[i];
	
	printf("\nStringa criptata -->  %s\n", str);

	for(i = 0; (i < 100 && str[i] != '\0'); i++)
    	str[i] = str[i] - crypt[i];
	
	printf("\nStringa decriptata --> %s\n", str);
   
   return 0;
}
