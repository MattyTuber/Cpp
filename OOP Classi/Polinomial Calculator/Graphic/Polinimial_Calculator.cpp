#include <iostream>
#include "Polinomial.h"

void menu()
{
	cout << "\t\t\t\t\t[ MENU ]\t\t\n\n";
	cout << "\t\t0) Termine Programma\n";
	cout << "\t\t1) Somma\n";
	cout << "\t\t2) Moltiplicazione\n";
	cout << "\t\t3) Divisione\n";
	cout << "\t\t4) Resto\n";
	cout << "\t\t5) Potenza\n";
	cout << "\t\t6) Derivata\n";
	cout << "\t\t7) Valutazione\n\n";

	cout << "\n - [ Inserire scelta ] --> ";
}

void header(){
	cout << "**************************************************************************************************\n\n";
	cout << "\t\t\t\t[ Polinomial Calculator ] \t\n\n";
	cout << "**************************************************************************************************\n\n";
}

int inDeg()
{
	int deg;

	cout << "\n - [\tSecondo Polinomio\t] - \n\tInserire Grado --> ";
	cin >> deg;

	return deg;
}

int main()
{
	int app, choice;
	int bin;

	header ();
	
	cout << " - [ Inserire Grado Polinomio Partenza ] --> ";
	cin >> app;
	cout << "\n";

	polinomio ans(app);
	ans.fill();

	polinomio temp;

	while (true)
	{
		temp.~polinomio();
		system("cls");
		header ();
		ans.print();
		cout << "\n\n";
		menu();
		cin >> choice;
		cout << "\n\n";

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
			cout << "\n\n**************************************************************************************************\n\n";
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
			cout << "\n\n**************************************************************************************************\n\n";
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
			cout << "\n\n**************************************************************************************************\n\n";
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
			cout << "\n\n**************************************************************************************************\n\n";
			system("pause");
			break;
		}

		case 5:
		{ //Potenza
			cout << "\n - [\tInserire Esponente\t] --> "; 
			cin >> app;

			ans = ans ^ app;
			ans.print();
			cout << "\n";
			cout << "\n\n**************************************************************************************************\n\n";
			system("pause");
			break;
		}

		case 6:
		{ //Derivata
			ans = ans.derivate();
			ans.print();
			cout << "\n";
			cout << "\n\n**************************************************************************************************\n\n";
			system("pause");
			break;
		}

		case 7:
		{ //Valutazione
			cout << "Inserire Termine Incognito --> ";
			cin >> app;

			cout << "Valutazione --> " << ans.value(app);
			cout << "\n";
			cout << "\n\n**************************************************************************************************\n\n";
			system("pause");	
			break;
		}
		
		case 333:
		{ //Members
			cout << "\n\t\t\t\t- [ Membri del Gruppo ] -\n\n";
			cout << "\t\t\t - Broglio 'TUBUS' Matteo "<< char (3)<<"\n";
			cout << "\t\t\t - Colombo 'COLOMBERS' Alessio "<< char (2)<<"\n";
			cout << "\t\t\t - Galuzzi 'SEANNY' Sean "<< char (1)<<"\n";
			cout << "\t\t\t - Garripoli 'K0RAKU' Fabio 'GARRY' Roberto "<< char (4)<<"\n";
			cout << "\t\t\t - Davide 'MUNNA' Lucca 'SPINNY' "<< char (5)<<"\n";
			cout << "\n\n";
			system("pause");
			break;
		}

		default:
			cout << "\t\t - [ Opzione Non Valida!!! Inserire altra opzione!!!] -\n\n ";
			system("pause");
			break;
		}
	}
}
