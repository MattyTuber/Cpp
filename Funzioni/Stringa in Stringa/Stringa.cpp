#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

int count(char *stringaBase, char *testoRicerca);

int main()
{
   	char a [100], b [100];

   	cout << "Inserire una stringa --> ";
   	gets(a);
   	cout << "Inserire il testo da cercare --> ";
   	gets(b);

   	cout << "Stringa trovata " << count (a, b) << " volte";

   	return 0;
}

int count(char *a, char *b)
{
   	int i, j, lena, lenb, cont=0;

   	lena=strlen(a);
   	lenb=strlen(b);
   
   	for (i=0; i < (lena - lenb + 1); i++)
   	{
      	for (j=0; j<lenb; j++){
      		if(a[i+j]!=b[j])
            	break;
		} 
      	
		if (j==lenb)
         	cont++;
   	}
   return cont;
}
