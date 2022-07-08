#include <iostream>

using namespace std;

class polinomio{
	public:
		polinomio(int grado){
			degree = grado;
			coef = new double[degree+1];
		}
		~polinomio(){}
		
		int getDegree(){
			return degree;
		}
		
	protected:
		double* coef;
	
	private:
		int degree;	
};

class parabola : public polinomio{
	public:
		parabola():polinomio(4){}
		
		void fill();
		void print();
};

void parabola::fill(){
	for (int i=0; i<polinomio::getDegree() + 1; i++){
		cout << "Inserire Coefficiente "<< i <<" Grado --> ";
		cin >> polinomio::coef[i];
	}
}

void parabola::print(){
	cout << "\n\nPolinomio\n";
	
	for (int i = polinomio::getDegree(); i >= 0; i--){
		if (i == 0)
			cout << polinomio::coef[i];
		else
			cout << polinomio::coef[i] << " x^" << i << " + ";
	}
}

int main(){
	parabola a;
	
	a.fill();
	a.print();
	
	return 0;
}
