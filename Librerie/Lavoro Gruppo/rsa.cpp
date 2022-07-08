#include <iostream>
#include <ctime>
#include <cstdlib>
#include "crypto.h"

using namespace std;

//Controllo che il numero generato random sia primo
//Restituisco 1 se il numero è primo
int prime(int num)
{
  int isPrime = 0, i;

  for (i = 2; i <= num / 2; ++i)
  {
    if (num % i == 0)
    {
      isPrime = 1;
      break;
    }
  }
  return isPrime;
}

int main(void)
{
  int num, num2, msg;
  srand(time(NULL));

  cout << "Inserire Messaggio da Criptare --> ";
  cin >> msg;

  do
  {
    num = rand() % 8 + 2;
  } while (prime(num) == 1); // Ripeto fino a quando il numero generato randomicamente non è primo

  do
  {
    num2 = rand() % 8 + 2;
  } while (prime(num2) == 1 || num2 == num); // Ripeto fino a quando il numero generato randomicamente non è primo

  cout << "\nPrimo Numero (p) --> " << num << endl;
  cout << "Secondo Numero (q) --> " << num2;

  cout << "\nMessaggio Criptato --> " << RSA_crypt(num, num2, msg) << endl;
  cout << "Messaggio Decriptato --> " << RSA_decrypt();
}
