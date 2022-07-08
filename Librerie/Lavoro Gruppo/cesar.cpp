#include <iostream>
#include "crypto.h"

using namespace std;

int main()
{
  char parola[128];
  char n;

  cout << "Inserire Parola da Criptare --> ";
  cin >> parola;

  cout << "Inserire l'Alfabeto da Usare --> ";
  cin >> n;

  cesar_crypt(parola, n);
  cout << "Parola Criptata --> " << parola << endl;

  cesar_decrypt(parola, n);
  cout << "Parola Decriptata --> " << parola;
}