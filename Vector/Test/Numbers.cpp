#include <iostream>
#include <vector>

using namespace std;

int main(){
	int input;
	
	vector <int> numbers;
	
	while(input != 999){
		cout << "Inserire Numero --> ";
		cin >> input;
		
		numbers.push_back(input);
	}
	
	numbers.pop_back();
	
	for(int n : numbers)
		cout << n << "\n";
	return 0;
}
