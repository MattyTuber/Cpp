#include <iostream>

using namespace std;

int main()
{
	char nome [50];
	int livello, stipendio;
	
	cout << "Inserire il nome --> ";
	cin >> nome;
	
	cout << "Inserire livello di appartenenza --> ";
	cin >> livello;
	
	switch (livello)
	{
		case 1:
			stipendio = 1000;
		break;
		
		case 2:
			stipendio = 1300;
		break;
		
		case 3:
			stipendio = 1500;
		break;
		
		case 4:
			stipendio = 1800;
		break;
		
		case 5:
			stipendio = 2000;
		break;
		
		default:
			cout << "Errore!!";
		break;
	}
	
	cout << "Stipendio --> " << stipendio;
}
