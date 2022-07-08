#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

typedef enum {STOP=13, VOLO=18, FUGA=28, SCALA=32, BOTOLA=30, CASCATA=41, SCORCIATOIA=44, FRANA=46};

using namespace std;

int gioco(int pos);

int main()
{
	int pos = 0, cont=0;
	
	srand(time(NULL));
	
	do{		
		pos = gioco(pos);
		
		cont++;
		
	} while (pos < 50);
	
	cout << "Terminato in " << cont << " mosse";

	return 0;
}

int gioco(int pos)
{	
	int dado;
	
	dado = rand()%6+1;
		
	pos += dado;
	
	cout << "Dado --> " << dado << endl;
	cout << "Posizione --> " << pos << endl;
	
	switch (pos)
	{
		case STOP:
			cout << "STOP" << endl;				
			pos -= 3;
				
		break;
			
			case FUGA:
			cout << "FUGA" << endl;
				
			pos -= 3;
				
		break;
			
		case CASCATA:
			cout << "CASCATA" << endl;
				
			pos -= 3;
				
		break;
		
		case FRANA:
			cout << "FRANA" << endl;
				
			pos -= 3;
				
		break;
			
		case VOLO:
			cout << "VOLO" << endl;
				
			pos += dado;
				
		break;
			
		case SCALA:
			cout << "SCALA" << endl;
				
			pos += dado;
				
		break;
			
		case SCORCIATOIA:
			cout << "SCORCIATOIA" << endl;
				
			pos += dado;
				
		break;
			
		case BOTOLA:
			cout << "BOTOLA" << endl;
			
			pos = 0;
				
		break;
			
		default:
		
		break;		
	}
	
	return pos;
}
