#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class pedina{
	public:
		pedina(double vita){
			life = vita;
		}
		
		virtual void attack(){}
	
	protected:
		double life;
};

class arciere : public pedina{
	public:
		arciere(double vita, int n):pedina(vita){
			arrows = n;
		}
		
		void attack(){			
			if (arrows == 0){
				cout << "Ho Finito le Frecce!!";
				exit(10);
			}
			else{
				cout << "Ho scagliato una freccia!!";
				arrows--;
			}
		}
		
	private:
		int arrows;
};

class lanciere : public pedina{
	public:
		lanciere(double vita):pedina(vita){}
		
		void attack(){
			cout << "Ho colpito con la lancia!!";
			
			life = life - life * 10 / 100;
		}
};

int main(){
	pedina *token;
	int choice;
	
	cout << "1. Arciere\n2. Lanciere\n";
	cout << "Scelta --> ";
	cin >> choice;
	
	switch(choice){
		case 1:
			token = new arciere(100, 3);
			while (true){
				cout << "\nAttaccare? (1/0)";
				cin >> choice;
				
				if (choice == 0)
					break;
					
				token->attack();
			}
		break;
		
		case 2:
			token = new lanciere(100);
			while (true){
				cout << "\nAttaccare? (1/0)";
				cin >> choice;
				
				if (choice == 0)
					break;
					
				token->attack();
			}
		break;
	}
	
	return 0;
}
