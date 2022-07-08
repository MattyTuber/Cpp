#include <iostream>

using namespace std;

int main(){
	int i = 0;
	
	int v [] = {4, 2, 6, 3, 5, 8, 9, 0, 7, 1};
	int w [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	while (i<10){
		w[v[i]] = i;		
		i = i + 1;
	}
	
	i = 0;
	
	for (i=0; i<10; i++){
		cout << w[i] << "\t";
	}
	
	return 0;
}
