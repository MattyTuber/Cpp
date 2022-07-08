#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

void rovescia (char []);

int main()
{
   	char vet [100];

   	cout << "Inserire una stringa --> ";
   	gets(vet);

   	rovescia(vet);
   	cout << vet;

   	return 0;
}

void rovescia (char v[])
{
	int i, l;
   	char temp;

   	l=strlen(v);
	
	for (i=0; i<l/2; i++)
	{
	    temp = v[i];
	    v[i] = v[l-1-i];
	    v[l-1-i] = temp;
	}
}
