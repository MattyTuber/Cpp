#include <iostream>

using namespace std;

class vett2d{
	public:
		vett2d(double x, double y);
		~vett2d(){}
		
		vett2d();
		
		double getX();
		double getY();
		
		void operator=(const vett2d& original);
		vett2d operator+(const vett2d& original);
		
		void stampa();
		
	protected:
		double x_p;
		double y_p;
};

class vett3d : public vett2d{
	public:
		vett3d (double x, double y, double z) : vett2d (x, y){
			z_p = z;
		}
		
	private:
		double z_p;
};

vett2d::vett2d(double x, double y){
	x_p = x;
	y_p = y;
}

vett2d::vett2d(){
	x_p = .1;
	y_p = .1;
}

double vett2d::getX(){
	return x_p;
}

double vett2d::getY(){
	return y_p;
}

void vett2d::operator=(const vett2d& original){
	x_p = original.x_p;
	y_p = original.y_p;
}

vett2d vett2d::operator+(const vett2d& original){
	double vet[2];
	
	vet[0] = x_p + original.x_p;
	vet[1] = y_p + original.y_p;
	
	vett2d vet_somma(vet[0], vet[1]);
	
	return vet_somma;
}

void vett2d::stampa(){
	cout << "X --> " << x_p << endl;
	cout << "Y --> " << y_p;
}

int main(){
	vett2d vett(2, 3.5);
	
	vett2d somma;
	
	somma = vett + vett;
	
	somma.stampa();
}
