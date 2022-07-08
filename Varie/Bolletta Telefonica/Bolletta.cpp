#include <iostream>
#include<string>

#define costo_abbonamento 26.80
#define costo_scatto 0.10

using namespace std;

int main()

{

	string nome;

	int scatti;

	float spesa;

	cout << "Inserire cognome e nome --> ";
	getline(cin, nome);

	cout << "Inserire il numero di scatti --> ";
	cin >> scatti;

	spesa = scatti * costo_scatto + costo_abbonamento;

	cout << "L' utente " << nome << " deve pagare " << spesa << " euro";

}
