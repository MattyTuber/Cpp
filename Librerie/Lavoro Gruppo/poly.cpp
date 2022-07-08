#include <iostream>
#include <cstdlib>
#include <ctime>
#include "crypto.h"

using namespace std;

void key_gen(char *word, int n) //Genoro una chiave randomicamente
{
  srand(time(NULL));

  for (int i = 0; i < n; i++)
    word[i] = rand() % 25 + 97;
}

int main()
{
  char parola[128];
  int N;

  cout << "Inserire una parola --> ";
  cin >> parola;

  cout << "Inserire Lunghezza Chiave --> ";
  cin >> N;

  char key[N];
  key_gen(key, N); // La chiave generata sarà una stringa (vettore di caratteri)

  cout << "Chiave --> " << key << endl;

  poly_crypt(parola, key);
  cout << "\nParola Criptata --> " << parola << endl;

  poly_decrypt(parola, key);
  cout << "Parola Decriptata --> " << parola;
}
