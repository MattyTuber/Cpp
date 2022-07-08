#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

bool find(vector <int> numbers, int n){
	for(int num : numbers)
		if (num == n)
			return true;
}

int main(){
	int num;
	srand(time(NULL));
	
	vector <int> numbers;
	
	for (int i = 0; i < 10; i++){
		num = rand()%10+1;
		num *= 10;
		
		numbers.push_back(num);
	}
		
	if(find(numbers, 10))
		cout << "FOUND!!";
		
	return 0;
}
