#include <iostream>

using namespace std;

int F(int x){
	int i = 0;
	while (x>0){
		if (x % 3 == 0)
			x = x / 3;
		else
			x = x - 1;
			
		i++;
	}
	
	return i;
}

int main(){
	int x = 0;
	int var;
	
	while (true){
		var = F(x);
		
		if (var == 6){
			cout << x;
			exit(20);
		}
		
		x++;
	}	
}
