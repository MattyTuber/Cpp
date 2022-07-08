#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int dim, num;
	
	srand(time(NULL));
	
	while(true){
		cout << "Cifre --> ";
		cin >> dim;
		
		if (dim == 404)
			break;
		
		for (int i = 0; i < dim; i++){
			num = rand()%100+1;
			
			if(num % 2 == 0)
				cout << "1";
			else
				cout << "0";
		}
			
		cout << "\n";
	}
	
	return 0;
}
