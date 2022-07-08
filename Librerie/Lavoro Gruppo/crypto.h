/* Copyright (C) 2020 Gruppo 1
   Libreria creata da Gruppo 1:
   Broglio Matteo
   Ceban Dan Eugen
   Colombo Alessio
   Galuzzi Sean
   Lucca Davide

   Questa Libreria contiene funzioni per criptare e decriptare messaggi

   cesar_crypt --> Cripta con il cifrario di Cesare
   cesar_decrypt --> Decripta con il cifrario di Cesare

   poly_crypt --> Cripta secondo il metodo polialfabetico
   poly_decript --> Decripta secondo il metodo polialfabetico

   RSA_crypt --> Cripta attraverso l'algoritmo RSA
   RSA_decrypt --> Decripta secondo l'algoritmo RSA
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

void cesar_crypt(char *parola, char n) //Funzione per la criptazione di cesare
{
  int len = strlen(parola); //Lunghezza parola
  int chiave = n - 97;

  for (int i = 0; i < len; i++) // Ripeto per ogni carattere

    if (parola[i] + chiave <= 122)
      parola[i] = parola[i] + chiave; // Aggiungo al codice ascii la chiave
    else
      parola[i] = parola[i] + (chiave - 26); //Aggiungo key al codice ascii della lettera poi decremento per ripartire da a
}

void cesar_decrypt(char *parola, char n) //Funzione per la decriptazione di cesare
{
  int len = strlen(parola); // Lunghezza Parola
  int chiave = n - 97;

  for (int i = 0; i < len; i++) // Ripeto per ogni carattere
    if (parola[i] - chiave >= 97)
      parola[i] = parola[i] - chiave; //Tolgo key al codice asii della lettera
    else
      parola[i] = parola[i] - (chiave - 26); //Tolgo key al codice ascii della lettera poi decremento per ripartire da a
}

void poly_crypt(char *parola, char *chiave) // Funzione per la Criptazione Polialfabetica
{
  int len = strlen(parola); //Lunghezza stringa parola
  int key;

  for (int i = 0; i < len; i++)
  {
    key = chiave[i] - 97; //Tolgo alla chiave il valore di a in ascii

    if ((int)parola[i] + key <= 122)
      parola[i] = parola[i] + key; //Aggiungo key al codice ascii della lettera

    else
      parola[i] = parola[i] + key - 26; //Aggiungo key al codice ascii della lettera e decremento per ripartire da a
  }
}

void poly_decrypt(char *parola, char *chiave) // Funzione per la Decriptazione Polialfabetica
{
  int len = strlen(parola); //Lunghezza stringa parola
  int key;

  for (int i = 0; i < len; i++)
  {
    key = chiave[i] - 97; //Tolgo alla chiave il valore di a in ascii

    if ((int)parola[i] - key >= 97)
      parola[i] = parola[i] - key; //Tolgo key al codice asii della lettera
    else
      parola[i] = parola[i] - (key - 26); //Tolgo key al codice ascii della lettera e decremento per ripartire da a
  }
}

// Funzioni Per RSA Crypt

int mod(int a, int n) // Restituisce il modulo tra due numeri
{
  return a % n;
}

int phi(int p, int q) // Calcola phi
{
  int phi = (p - 1) * (q - 1);
  return phi;
}

int mcd(int e, int ph) // Calcola mcd
{
  int t = __gcd(e, ph); // Utilizzo __gcd che è una funzione della libreria algorithm

  return t;
}

int e; // Variabile Globale

int public_key(int ph) // Calcolo la chiave pubblica (e)
{
  int gcd;
  e = 2;

  while (e < ph) // Controllo che siano Co-Primi
  {
    gcd = mcd(e, ph); // Richiamo funzione mcd

    if (gcd == 1)
      return e; // Ritorno il numero Co-Primo
    else
      e++;
  }
}

//variabili globali
//Richiamo queste variabili nelle altre funzioni senza passarle come argomento
int crypt, pub_key, n, ph;
int RSA_crypt(int p, int q, int msg) // Funzione per criptare il messaggio RSA
{
  n = p * q;
  cout << "\nN --> " << n << endl;

  ph = phi(p, q); // Richiamo funzione phi
  cout << "Phi --> " << ph << endl;

  pub_key = public_key(ph); // Richiamo funzione public_key
  cout << "Chiave Pubblica --> " << pub_key << endl;

  crypt = pow(msg, pub_key);

  crypt = mod(crypt, n); // Richiamo funzione mod

  return crypt; // Ritorno la frase criptata
}

//Funzioni per RSA Decrypt

float decrypt;      //Variabile globale
float private_key() // Genero la chiave privata, per decriptare
{
  decrypt = (1 + (2 * ph)) / pub_key; // 2 è un valore dato arbitrariamente
  return decrypt;
}

float RSA_decrypt() // Funzione per decriptare il messaggio RSA
{
  cout << "Chiave di Decriptazione --> " << private_key() << endl;

  float dec = pow(crypt, decrypt); // Messaggio Criptato elevato a Chiave di Decriptazione

  /*Variabile "munna" utilizzata in un momento di estrema frustrazione per debuggare il codice.
  Sarebbe stato possibile ripetere dec = fmod...*/
  float munna = fmod(dec, n); // Modulo tra dec e (p*q)

  return munna; // Ritorno la frase decriptata
}