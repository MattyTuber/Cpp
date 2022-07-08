#include <iostream>
#include <cmath>

using namespace std;

class sup{
	public:
		sup(double a){
			area = a;
		}
		
		double getArea(){
			return area;
		}
		
		virtual double perimeter(){}
		
	protected:
		double area;
};

class circle : public sup{
	public:
		circle (double a) : sup (a){}
		
		double perimeter(){
			double p = 2*sqrt(M_PI*area);
			return p;
		}
};

class square : public sup{
	public:
		square (double a) : sup (a){}
		
		double perimeter(){
			double p = 4*sqrt(area);
			return p;
		}
};

int main(){
	sup *figura;
	int choice;
	double ar;
	
	cout << "1. Cerchio\n";
	cout << "2. Quadrato\n\n";
	cout << "Scelta --> ";
	cin >> choice;
	
	cout << "\nInserire Area --> ";
	cin >> ar;
	
	switch(choice){
		case 1:			
			figura = new circle(ar);
			cout << "\nPerimeter --> " << figura->perimeter();
		break;
			
		case 2:
			figura = new square(ar);
			cout << "\nPerimeter --> " << figura->perimeter();
		break;
	}
	
	return 0;
}
