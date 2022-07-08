#include <iostream>

using namespace std;

class vect3d{
	public:
		vect3d(int a[]);
		~vect3d(){}
		
		void operator=(const vect3d& original);
		vect3d operator+(const vect3d& original);
		bool operator==(const vect3d& original);
		
		void print();
		
	private:
		int vect[3];		
};

vect3d::vect3d(int a[]){
	for (int i = 0; i < 3; i++)
		vect[i] = a[i];
}

void vect3d::print(){
	for (int i = 0; i < 3; i++)
		cout << vect[i] << "\t";
}

void vect3d::operator=(const vect3d& original){
	for (int i = 0; i < 3; i++)
		vect[i] = original.vect[i];
}

vect3d vect3d::operator+(const vect3d& original){
	int somma [3];
	
	for (int i = 0; i < 3; i++)
		somma [i] = vect[i] + original.vect[i];
		
	vect3d sum(somma);
	
	return sum;
}

bool vect3d::operator==(const vect3d& original){
	if (vect[0] == original.vect[0])
		if (vect[1] == original.vect[1])
			if (vect[2] == original.vect[2])
				return true;
	
	return false;
}

int main(){
	int v[3];
	int v2[3];
	
	cout << "Primo Vettore\n\n";
	
	for (int i = 0; i < 3; i++){
		cout << "Inserire un valore --> ";
		cin >> v[i];
	}
	
	cout << "\n\nSecondo Vettore\n\n";
	
	for (int i = 0; i < 3; i++){
		cout << "Inserire un valore --> ";
		cin >> v2[i];
	}
	
	vect3d array(v);
	vect3d array2(v2);
	
	if (array == array2)
		cout << "\n\nArray Uguali";
	else
		cout << "\n\nArray Diversi";
	
	vect3d sum = array + array2;
	cout << "\n\nSomma --> ";
	sum.print();
	
	return 0;
}
