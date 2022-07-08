#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
   int N, i;

   cout << "Inserire il numero di valori --> ";
   cin >> N;

   int a[N];

   for (i = 0; i < N; ++i)
   {
      cout << "Inserire un numero --> ";
      cin >> a[i];
   }

   for (i=i-1; i >= 0; --i)
   {
      cout << a[i] << "\t";
   }
   return 0;
}