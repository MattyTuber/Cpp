#include <iostream>

using namespace std;

int main(){	
	int m [200] [200] [200];
	int v [] = {6, 19, 64, 72, 81};
	
	int i, j, k, t;
	
	i = 0;
	
	while (i < 100){
		j = 0;
		
		while (j < 100){
			k = 0;
			
			while (k < 100){
				if (i * j == k)
					m [i] [j] [k] = 1;
				else
					m [i] [j] [k] = 0;
					
				k++;
			}
			
			j++;
		}
		
		i++;
	}
	
	k = 0;
	
	while (k < 5){
		t = 0;
		i = 0;
		
		while (i < 100){
			j = 0;
			
			while (j < 100){
				t = t + m [i] [j] [v[k]];
				
				j++;
			}
			
			i++;
		}
		
		cout << t << "\t";
		
		k++;
	}
	
	return 0;
}
