#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class transport{
	public:
		transport(double serbatoio){
			tank = serbatoio;
		}
		
		virtual void start(){}
		
		virtual void stop(){}
		
		void print(){
			cout << "Carburante Rimanente --> " << tank << "\n\n";
		}
		
	protected:
		int t;
		double tank, consume;
};

class stationWagon : public transport{
	public:
		stationWagon(double serbatoio) : transport(serbatoio){}
		
		void start(){
			t = time(NULL);
		}
		
		void stop(){
			t = time(NULL) - t;
			consume = tank * 0.07 / 100;
			tank = tank - t * consume;
		}
};

class cityCar : public transport{
	public:
		cityCar(double serbatoio) : transport(serbatoio){}
		
		void start(){
			t = time(NULL);
		}
		
		void stop(){
			t = time(NULL) - t;
			consume = tank * 0.01 / 100;
			tank = tank - t * consume;
		}
};

void case1(){
	transport *car;
	car = new stationWagon(100);
	
	int choice;
	
	while(true){
		cout << "1. Start";
		cout << "\n2. Stop";
		cout << "\nInserire 10 per terminare";
		cout << "\n\nScelta --> ";
		cin >> choice;
		
		system("cls");
		
		switch(choice){
			case 1:
				car -> start();
			break;
				
			case 2:
				car -> stop();
				car -> print();
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

void case2(){
	transport *car;
	car = new cityCar(100);
	
	int choice;
	
	while(true){
		cout << "1. Start";
		cout << "\n2. Stop";
		cout << "\nInserire 10 per terminare";
		cout << "\n\nScelta --> ";
		cin >> choice;
		
		system("cls");
		
		switch(choice){
			case 1:
				car -> start();
			break;
				
			case 2:
				car -> stop();
				car -> print();
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

int main(){
	int scelta;
	
	cout << "1. Station Wagon" << endl,
	cout << "2. City Car" << endl;
	
	cout << "\nScelta --> ";
	cin >> scelta;
	
	system("cls");
	
	switch(scelta){
		case 1:
			case1();
		break;
		
		case 2:
			case2();
		break;
		
		default:
			cout << "Scelta Non Valida!!";
	}
}
