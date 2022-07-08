#include <iostream>
#include <string>

using namespace std;

template <class T>
T abs (T n){
	if (n < 0)
		return n * -1;
	else
		return n;
}

template <class T>
T sort(T *a, int size){
	int min;
	
	for(int i=0; i<size-1; i++){
		min = i;
	    for(int j=i+1; j<size; j++)
	        if (a[j] < a[min])
	        	min = j;
	
	    T temp = a[min];
	    a[min] = a[i];
	    a[i] = temp;
    }
}

int main(){
	int inum = -1;
	double fnum = -1.5;
	
	int iarray [] = {1, 6, 8, 2};
	double farray [] = {1.5, 6.2, 8.7, 2.2};
	char sarray[] = "ciao"; // Non si possono utilizzare stringhe
	
	sort(iarray, 4);
	for (int i = 0; i < 4; i++)
		cout << iarray[i] << " ";
		
	cout << "\n";
		
	sort(farray, 4);
	for (int i = 0; i < 4; i++)
		cout << farray[i] << " ";
		
	cout << "\n";
	
	sort(sarray, 4);
	for (int i = 0; i < 4; i++)
		cout << sarray[i];
	
	cout << "\n\nAbsolute --> " << abs <int> (inum);
	cout << "\nAbsolute --> " << abs <float> (fnum);
}
