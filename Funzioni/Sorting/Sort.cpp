#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void sort(int vettore[], int lunghezza, int sorting);

int main()
{
   	int vet [100];
   	int i, leng, sor;

   	cout << "Inserire il numero di valori --> ";
   	cin >> leng;

   	for (i=0; i<leng; i++){
      cout << "Inserire un valore --> ";
      cin >> vet [i];
   	}

   	cout << "Crescente [1] Decrescente [2] --> ";
   	cin >> sor;
   
   	sort (vet, leng, sor);
   
   	for (i=0; i<leng; i++)
      cout << vet [i];
   
   	return 0;
}


void sort (int v[], int len, int ord)
{
   int i, j;
   int temp;

   for (i=0; i<len-1; i++)
      for (j=i+1; j<len; j++)
         if (ord==1 && v[i] > v[j]){
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
         }
         else if (ord==0 && v[i] < v[j]){
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
         }
}
