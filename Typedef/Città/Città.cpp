#include <iostream>
#include <cstdio>

typedef enum {MILANO = 1, TORINO, GENOVA, VENEZIA, BOLOGNA, FIRENZE, ANCONA, PERUGIA, ROMA, FINE} citta;

using namespace std;

int main()
{
	citta city;
	bool end = false;

	cout << "1 - Milano\n2 - Torino\n3 - Genova\n4 - Venezia\n5 - Bologna\n6 - Firenze\n7 - Ancona\n8 - Perugia\n9 - Roma\n10 - Terminare\n\n";
	cout << "Inserie il luogo di partenza --> ";
	scanf("%d", &city);
	
	do{

		switch (city)
		{
			case MILANO:
				cout << "Puoi andare a Torino, Venezia, Bologna, Firenze, Roma";
				
				break;
				
			case TORINO:
				cout << "Puoi andare a Milano e Genova";
				
				break;
				
			case GENOVA:
				cout << "Puoi andare a Torino e Venezia";
				
				break;
				
			case VENEZIA:
				cout << "Puoi andare a Milano, Genova e Bologna";
				
				break;
				
			case BOLOGNA:
				cout << "Puoi andare a Milano, Venezia e Firenze";
				
				break;
				
			case FIRENZE:
				cout << "Puoi andare a Milano, Bologna e Ancona";
				
				break;
				
			case ANCONA:
				cout << "Puoi andare a Firenze e Perugia";
				
				break;
				
			case PERUGIA:
				cout << "Puoi andare ad Ancona e Roma";
				
			case ROMA:
				cout << "Puoi andare a Milano, Torino, Genova, Venezia e Bologna";
				
				break;
				
			case FINE:
				bool end = true;
				
				break;
				
			default:
				cout << "Errore! Reinserire";
		}
	
	}while (!end)
		
	return 0;
}

