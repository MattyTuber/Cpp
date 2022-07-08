#include <iostream>

using namespace std;

template <class T>
class calc{
	public:
		T sum(T val1, T val2){
			return val1 + val2;
		}
		
		T sub(T val1, T val2){
			return val1 - val2;
		}
		
		T div(T val1, T val2){
			return val1 / val2;
		}
		
		T mult(T val1, T val2){
			return val1 * val2;
		}
};

int main(){
	int i1 = 4, i2 = 2;
	double d1 = 4.4, d2 = 2.2;
	char c1 = 'A', c2 = 'a';
	
	calc <int> a;
	
	cout << "Somma --> " << a.sum (i1, i2);
	cout << "\nSottrazione --> " << a.sub (i1, i2);
	cout << "\nDivisione --> " << a.div (i1, i2);
	cout << "\nMoltiplicazione --> " << a.mult (i1, i2);
}
