#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class cronometro{
	public:
		~cronometro(){}
		
		void start();
		void stop();
		
		void print();
		
	private:
		int t1, t2;
};

void cronometro::start(){
	t1 = time(NULL);
}

void cronometro::stop(){
	t2 = time(NULL);
}

void cronometro::print(){
	cout << "Tempo Trascorso --> " << t2 - t1 << "\n\n";
}

int main(){
	int choice;
	cronometro stopwatch;
	
	while(true){
		cout << "1. Start";
		cout << "\n2. Stop";
		cout << "\n3. Print";
		cout << "\nInserire 10 per terminare";
		cout << "\n\nScelta --> ";
		cin >> choice;
		
		system("cls");
		
		switch(choice){
			case 1:
				stopwatch.start();
				break;
				
			case 2:
				stopwatch.stop();
				break;
				
			case 3:
				stopwatch.print();
				break;
				
			case 10:
				exit(10);
				break;
				
			default:
				cout << "Opzione Non Valida!!\n\n";
				break;
		}
	}
}
