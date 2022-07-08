#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	char c;
	
	cout << "Numeri da Inserire --> ";
	cin >> N;
	
	string fake = "";
	
	for (int i = 0; i < N; i++){
		cout << "Inserire Crattere --> ";
		cin >> c;
		
		fake = fake + c + " ";
	}
		
		
	cout << fake;
}
