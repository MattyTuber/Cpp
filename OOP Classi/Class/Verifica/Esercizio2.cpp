#include <iostream>

using namespace std;

class point{
	public:
		point (double x, double y);
		point ();
		point (const point& original);
		~point(){}
		
		void operator=(const point& original);
		point operator+(const point& original);
		
		void print();
		
	private:
		int x_p, y_p;		
};

point::point(double x, double y){
	x_p = x;
	y_p = y;
}

point::point(){
	x_p = 0;
	y_p = 0;
}

point::point(const point& original){
	x_p = original.x_p;
	y_p = original.y_p;
}

void point::operator=(const point& original){
	x_p = original.x_p;
	y_p = original.y_p;
}

point point::operator+(const point& original){
	double ex, uai;
	
	ex = x_p + original.x_p;
	uai = y_p + original.y_p;
	
	point somma(ex, uai);
	
	return somma;
}

void point::print(){
	cout << "X --> " << x_p << endl;
	cout << "Y --> " << y_p;
}

int main(){
	point a(2, 2);
	point b;
	point c(a);
	
	point somma = a + b + c;
	
	somma.print();
}
