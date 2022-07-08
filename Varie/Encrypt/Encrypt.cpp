#include <stdio.h>
#include <cstdlib>
#include <ctime>

int main()
{
   	int i, x;
  	char str[100];
  	int crypt [100];
  	
  	srand(time(NULL));

   	printf("Inserire una stringa --> ");
   	gets(str);
   	
   	for (i = 0; i < 100; ++i)
	{
		crypt[i] = rand()%126+1;
	}
      
	for(i = 0; (i < 100 && str[i] != '\0'); i++)
    	str[i] = str[i] + crypt[i];
    	
    //Controllare se inferiore a 127

    printf("\nStringa Criptata--> %s\n", str);
      
   return 0;
}
