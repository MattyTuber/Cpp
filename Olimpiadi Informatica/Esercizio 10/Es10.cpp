#include <iostream>

using namespace std;

int F(int h, int i){
	if (i == 0 || i == h - 1)
		return 1;
	
	if (i < 0 || i >= h)
		return 0;
	
	return F(h-1, i-1) + F(h-1, i);
}

int main(){
	int i = 0;
	int var;
	
	while (i < 4){
		cout << F(4, i) << "\t";
		
		i++;
	}
	
	return 0;	
}
