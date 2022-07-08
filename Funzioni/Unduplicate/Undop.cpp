#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
	int len, i, j, k;
	char a[100], b[100];
	
	cout << "Inserire una stringa --> ";
	gets(a);
	
	len = (int)strlen(a);
	
	for (i=0; i<len; i++){
		for (j=i-1; j>=0 && a[j] != a[i]; j--)
			;
		if (j>=0)
         	a[i] = '\0';
	}
	
	cout << a;
	
	k=-1;
   	for (i=0; i<len; i++)
      	if (a[i] != '\0')
         	a[++k]=a[i];
   	a[++k] = '\0';
}
