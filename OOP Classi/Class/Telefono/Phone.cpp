#include <bits/stdc++.h>

using namespace std;

class batteria{
	public:
		void sms(){
			battery -= 1;
		}
		
		void charge(){
			battery = 100;
		}
		
		void call();
		
		int getBattery(){
			return battery;
		}
		
	private:
		int battery = 100;
};

void batteria::call(){
	int sec;
	
	cout << "Durata Chiamta --> ";
	cin >> sec;
	
	battery -= sec/5;
}

void wait(){
	cin.ignore();
	cin.ignore();
}

int main(){
	batteria pocoX3;
	int choice;
	
	while(true){
		system("cls");
		
		cout << "1. SMS";
		cout << "\n2. Call";
		cout << "\n3. Charge";
		cout << "\n4. Battery Status";
		cout << "\nAny key to end..";
		cout << "\n\nScelta --> ";
		cin >> choice;
		
		switch(choice){
			case 1:
				cout << "Messaging..";
				pocoX3.sms();
				wait();
			break;
			
			case 2:
				cout << "Calling..\n";
				pocoX3.call();
			break;
			
			case 3:
				cout << "Charging..";
				pocoX3.charge();
				wait();
			break;
			
			case 4:
				cout << "Phone Battery --> " << pocoX3.getBattery() << "%";
				wait();
			break;
			
			default:
				exit(10);
		}
	}
	
	return 0;
}
