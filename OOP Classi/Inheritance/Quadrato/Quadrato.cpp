#include <iostream>

using namespace std;

class rettangolo{
	public:
		rettangolo(double lato1, double lato2);
		~rettangolo(){}
		
		double getArea();
		double getPerimeter();
		
	private:
		double l1, l2;
};

rettangolo::rettangolo(double lato1, double lato2){
	l1 = lato1;
	l2 = lato2;
}

double rettangolo::getArea(){
	return l1 * l2;
}

double rettangolo::getPerimeter(){
	return l1 * 2 + l2 * 2;
}

class quadrato : public rettangolo{
	public:
		quadrato (double lato1) : rettangolo(lato1, lato1){} // Richiamo La Superclasse, i parametri che passerò a rettangolo saranno gli stessi
};

int main()
{
	quadrato square (1.5);
	
	cout << "Area --> " << square.getArea() << endl;
	cout << "Perimetro --> " << square.getPerimeter();
}
