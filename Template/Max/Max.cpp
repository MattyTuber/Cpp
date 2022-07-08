#include <iostream>

using namespace std;

template <class T>
T getMax (T n1, T n2){
	if (n1 > n2)
		return n1;
	else
		return n2;
}

class quadrato {
	public:
		quadrato (double lato){
			side = lato;
		}
		
		double getSide(){
			return side;
		}
		
		void operator=(const quadrato& original){
			side = original.side;
		}
		
		bool operator>(const quadrato& original);
		
	private:
		double side;
};

bool quadrato::operator>(const quadrato& original){
	if (side > original.side)
		return true;
	else
		return false;
}

class cerchio {
	public:
		cerchio (double raggio){
			radius = raggio;
		}
		
		double getRadius(){
			return radius;
		}
		
		void operator=(const cerchio& original){
			radius = original.radius;
		}
		
		bool operator>(const cerchio& original);
		
	private:
		double radius;
};

bool cerchio::operator>(const cerchio& original){
	if (radius > original.radius)
		return true;
	else
		return false;
}

int main(){
	quadrato a (1.5);
	quadrato b (2);
	
	quadrato big = getMax <quadrato> (a, b);
	
	double x = 1.5;
	double y = 3.6;
	
	cerchio r1 (1.5);
	cerchio r2 (15.3);
	
	cerchio maximum = getMax <cerchio> (r1, r2);
	
	cout << "Biggest Quadrato --> " << big.getSide();
	cout << "\nBiggest Double --> " << getMax (x, y);
	cout << "\nBiggest Cerchio --> " << maximum.getRadius();
	
	return 0;
}
