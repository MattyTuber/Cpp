#include <iostream>
#include "Polinomial.h"

void menu()
{
	cout << "\t\t[ MENU ]\t\t\n\n";
	cout << "\t1) Somma\n";
	cout << "\t2) Moltiplicazione\n";
	cout << "\t3) Divisione\n";
	cout << "\t4) Resto\n";
	cout << "\t5) Potenza\n";
	cout << "\t6) Derivata\n";
	cout << "\t7) Valutazione\n";

	cout << "\nInserire scelta --> ";
}

int inDeg()
{
	int deg;

	cout << "Secondo Polinomio\nInserire Grado --> ";
	cin >> deg;

	return deg;
}

int main()
{
	int app, choice;
	int bin;

	cout << "Inserire Grado Polinomio Partenza --> ";
	cin >> app;

	polinomio ans(app);
	ans.fill();

	polinomio temp;

	while (true)
	{
		temp.~polinomio();
		system("cls");
		menu();
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 0: //END
			cout << "Programma Terminato!!";
			return 0;
			break;

		case 1:
		{ //Somma
			polinomio temp(inDeg());
			temp.fill();

			ans = ans + temp;
			ans.print();
			cout << "\n";
			system("pause");
			break;
		}

		case 2:
		{ //Moltiplicazione
			polinomio temp(inDeg());
			temp.fill();

			ans = ans * temp;
			ans.print();
			cout << "\n";
			system("pause");
			break;
		}

		case 3:
		{ //Divisione
			polinomio temp(inDeg());
			temp.fill();

			ans = ans / temp;
			ans.print();
			cout << "\n";
			system("pause");
			break;
		}

		case 4:
		{ //Resto
			polinomio temp(inDeg());
			temp.fill();

			temp = ans % temp;
			temp.print();
			cout << "\n";
			system("pause");
			break;
		}

		case 5:
		{ //Potenza
			cout << "(";
			ans.print();
			cout << ")^";
			cin >> app;

			ans = ans ^ app;
			ans.print();
			cout << "\n";
			system("pause");
			break;
		}

		case 6:
		{ //Derivata
			ans = ans.derivate();
			ans.print();
			cout << "\n";
			system("pause");
			break;
		}

		case 7:
		{ //Valutazione
			cout << "Inserire Termine Incognito --> ";
			cin >> app;

			cout << "Valutazione --> " << ans.value(app);
			cout << "\n";
			system("pause");
			break;
		}

		default:
			cout << "Opzione Non Valida!!";
			break;
		}
	}
}