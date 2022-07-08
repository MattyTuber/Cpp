#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class dado{
	public:		
		virtual int lancia(){
			return rand()%faces+1;
		}
	
	protected:
		int faces;
};

class dado4 : public dado{
	public:
		dado4(){
			faces = 4;
		}
};

class dado6 : public dado{
	public:
		dado6(){
			faces = 6;
		}
};

class dado20 : public dado{
	public:
		dado20(){
			faces = 20;
		}
};

int main(){
	srand(time(NULL));
	
	dado *dice;
	int choice;
	
	cout << "Inserire Scelta --> ";
	cin >> choice;
	
	switch (choice){
		case 1:
			dice = new dado4();
			cout << "Lancio --> " << dice->lancia();
		break;
		
		case 2:
			dice = new dado6();
			cout << "Lancio --> " << dice->lancia();
		break;
		
		case 3:
			dice = new dado20();
			cout << "Lancio --> " << dice->lancia();
		break;
	}
	
	return 0;
}
