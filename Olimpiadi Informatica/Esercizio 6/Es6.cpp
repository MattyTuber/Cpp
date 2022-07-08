#include <iostream>

using namespace std;

int main(){
	int i = 0;
	int s = 2;
	int t = 0;
	
	while (i<8){
		i = i + 1;
		s = s * 2;
		t = t + s + i;
	}
	
	cout << t;
}
