#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXR 20
#define MAXC 26

using namespace std;

int main()
{
   int NR, NC, i, j, cont, n, m, no_Output;
   int big_matrice [MAXR] [MAXC];
   
   srand(time(NULL));

   for (i=0; i<MAXR; i++)
   {
      for (j=0; j<MAXC; j++)
      {
         big_matrice [i] [j] = rand() % 100;
         cout << big_matrice [i] [j] << "\t";
      }
      
      cout << endl;
   }

   cout << "Inseire il numero di righe --> ";
   cin >> NR;

   cout << "Inserire il numero di colonne --> ";
   cin >> NC;

   int matrice [NR] [NC];

   for (i = 0; i < NR; ++i)
   {
      for (j = 0; j < NC; ++j)
      {
         cout  << "Inserire un valore --> ";
         cin >> matrice [i] [j];
      }
   }

   no_Output = 0;

   for (i=0; i<=MAXR-NR; ++i)
   {
      for (j=0; j<=MAXC-NC; ++j)
      {
         cont = 0;
         
         for (n=0; n<NR; ++n)
            
            for (m=0; m<NC; ++m)
               
               if (big_matrice[i+n][j+m] == matrice[n][m])
                  cont++;
         
         if (cont == NR*NC)
         {
            no_Output++;
            cout << "Trovata alle coordinate --> " << i+1 << " , " << j+1 << endl;
         }
            
      }
   }

   if (no_Output == 0)
      cout << "Nessuna corrispondenza trovata";

   return 0;
}