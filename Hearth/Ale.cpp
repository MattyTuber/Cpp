#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int r;
	
	srand(time(NULL));
	
	while(true){
		cout << char(3);
		
		r = rand()%100;
		if (r % 2 == 0)
			cout << "\t";
		else
			cout << "LOVE YOU!!\n";
	}
}
