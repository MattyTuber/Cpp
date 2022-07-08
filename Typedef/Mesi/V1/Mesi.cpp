#include <iostream>
#include <cstdio>

typedef enum {GEN=1, FEB, MAR, APR, MAG, GIU, LUG, AGO, SET, OTT, NOV, DIC} mesi;
typedef enum {SAT, SUN, MON, TUE, WED, THU, FRI} giorni;

using namespace std;

int main()
{
	
	int giorno, year, day_totali = 0, day_trascorsi, year4, year100, year400, day;
	bool bisestile = false;
	mesi month;
	
	cout << "Inserire una data (gg/mm/aaaa) --> ";
	scanf("%d/%d/%d", &giorno, &month, &year);
	//printf("%02d / %02d / %04d\n", giorno, month, year);
		
	switch (month)
	{
		case GEN:
				
			cout << "Gennaio" << endl;
				
			//Siccome devo calcolare i giorni dall'inizio dell'anno, se il mese inserito è gennaio mi basta prendere in considerazione il giorno da me inserito
			day_totali = giorno;
				
			if (giorno<=0 || giorno>31)
				cout << "La data non è valida";
						
		break;
			
		case FEB:
			
		cout << "Febbraio" << endl;
			
		//Per calcolare i giorni trascorsi dall'inizio dell'anno prendo i giorni totali del mese in cui mi trovo e dei mesi precedenti, li sommo e poi tolgo ai giorni totali i giorni totali del mese in cui mi trovo meno il giorno da me inserito
		day_totali = 59 - (28 - giorno);
				
		if (year%400 == 0 || (year%4 == 0 && !(year%100==0)))
		{
			bisestile = true;
			
			cout << "L'anno e' bisestile" << endl;
				
			if (giorno<=0 || giorno>29)
				cout << "La data non e' valida";
		}
				
		break;
			
		case MAR:
				
			cout << "Marzo" << endl;
				
			day_totali = 90 - (31 - giorno);
							
			if (giorno<=0 || giorno>31)
				cout << "La data non è valida"; 
				
		break;
			
		case APR:
				
			cout << "Aprile" << endl;
				
			day_totali = 120 - (30 - giorno);
				
			if (giorno<=0 || giorno>30)
				cout << "La data non e' valida";
				
		break;
		
		case MAG:
				
			cout << "Maggio" << endl;
			
			day_totali = 151 - (31 - giorno);
				
			if (giorno<=0 || giorno>31)
				cout << "La data non e' valida";
				
		break;
			
		case GIU:
			
			cout << "Giugno" << endl;
				
			day_totali = 181 - (30 - giorno);
				
			if (giorno<=0 || giorno>30)
				cout << "La data non e' valida";
				
		break;
			
		case LUG:
				
			cout << "Luglio" << endl;
				
			day_totali = 212 - (31 - giorno);
				
			if (giorno<=0 || giorno>31)
				cout << "La data non e' valida";
				
		break;
		
		case AGO:
				
			cout << "Agosto" << endl;
				
			day_totali = 243 - (31 - giorno);
				
			if (giorno<=0 || giorno>31)
				cout << "La data non e' valida";
				
		break;
			
		case SET:
				
			cout << "Settembre" << endl;
				
			day_totali = 273 - (30 - giorno);
				
			if (giorno<=0 || giorno>30)
				cout << "La data non e' valida";
				
		break;
			
		case OTT:
			
			cout << "Ottobre" << endl;
				
			day_totali = 304 - (31 - giorno);
			
			if (giorno<=0 || giorno>31)
				cout << "La data non e' valida";
				
		break;
			
		case NOV:
				
			cout << "Novembre" << endl;
				
			day_totali = 334 - (30 - giorno);
			
			if (giorno<=0 || giorno>30)
				cout << "La data non e' valida";
				
		break;
			
		case DIC:
				
			cout << "Dicembre" << endl;
				
			day_totali = 365 - (31 - giorno);
				
			if (giorno<=0 || giorno>31)
				cout << "La data non e' valida";
		
		break;
			
		default:
				
			cout << "Il mese non e' valido";
	
		break;
	}
	
	if (bisestile == true)
		day_totali = 60 - (29 - giorno);
	
	//Se il mese da me inserito non è febbraio controllo che non sia nemmeno gennaio e nel caso che sia un anno bisestile, in quel caso aggiungo 1 ossia il giorno in più di febbraio
	else if ((year%400 == 0 || (year%4 == 0 && !(year%100==0))) && month != GEN)
		day_totali += 1;		
		
	year4 = year / 4;
	
	year100 = year / 100;
	
	year400 = year / 400;
	
	day = year + year4 - year100 + year400 + day_totali;

	switch (day % 7)
	{
		case SAT:
			
			printf ("%02d / %02d / %04d e' Sabato", giorno, month, year);
			
		break;
		
		case SUN:
			
			printf ("%02d / %02d / %04d e' Domenica", giorno, month, year);
			
		break;
		
		case MON:
			
			printf ("%02d / %02d / %04d e' Lunedi'", giorno, month, year);
			
		break;
		
		case TUE:
			
			printf ("%02d / %02d / %04d e' Martedi'", giorno, month, year);
			
		break;
		
		case WED:
			
			printf ("%02d / %02d / %04d e' Mercoledi'", giorno, month, year);
			
		break;
		
		case THU:
			
			printf ("%02d / %02d / %04d e' Giovedi'", giorno, month, year);
			
		break;
		
		case FRI:
			
			printf ("%02d / %02d / %04d e' Venerdi'", giorno, month, year);
			
		break;
	}
	
	return 0;
}
