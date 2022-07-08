#include <iostream>

using namespace std;

int main()
{
   int i, N, ripetizioni, maxQ, valoremax;
 
   cout << "Inserire il numero di valori --> ";
   cin >> N;

   int vett[N];

   for (i = 0; i < N; ++i)
   {
      cout << "Inserire un valore --> ";
      cin >> vett[i];
   }

   maxQ = 1;
   ripetizioni = 1;
   valoremax = vett[0];
   
   for (i=1; i < N; i++)
   {
      if (vett[i] == vett[i-1])
      {
         ripetizioni++;
         
         if (ripetizioni>maxQ)
         {
            maxQ=ripetizioni;
            valoremax=vett[i];
         }
      }
      else
         
         ripetizioni=1;
   }

   cout << "Numero -> " << valoremax << " Ripetizioni -> " << maxQ;

   return 0;
}