#include <algorithm>
#include <iostream>

using namespace std;

class polinomio{
	public:
		// CONSTRUCTORS AND DESTRUCTOR
	    polinomio(int grado){
			deg = grado;
			coef = new double[deg+1];
		}
	    
	    polinomio(){
	      deg = 0;
	      coef = new double [1];
		  coef [0] = 1;
	    }
	
	    polinomio(const polinomio& original){
	      deg = original.deg;
	      coef = original.coef;
	    }
	
		~polinomio(){}
	
	    //METODI GET		
		int getDeg(){
			return deg;
		}
	
	    //METODI
	    void fill();
	    void print();
	    
		void setCoef(const double* v);
		void setDeg(const int& degree);
		
		double value(const double& x);
		polinomio derivate();
		
		//OVERLOADING OPERATORI
		void operator=(const polinomio& original){
			deg = original.deg;
			coef = original.coef;
		}
		
		polinomio operator+(const polinomio& original);
		polinomio operator*(const polinomio& original);
		polinomio operator*(const double& k);
		polinomio operator^(const int& n);
		polinomio operator/(const polinomio& original);
		polinomio operator%(const polinomio& original);
	
		private:
			int deg;
			double* coef;
};

void polinomio::fill(){
  	for (int i=0; i < deg + 1; i++){
		cout << "Inserire Coefficiente "<< i <<" Grado --> ";
		cin >> polinomio::coef[i];
	}
}

void polinomio::print(){	  	
	for (int i = deg; i >= 0; i--){
		if (coef[i] == 0)
			continue;
		
		if (i == 0)
			cout << showpos << coef[i];
		else if (i == 1)
			cout << showpos << coef[i] << " x ";
		else
			cout << showpos << coef[i] << " x^" << noshowpos << i << " ";
	}
}

void polinomio::setCoef(const double* v){
	for (int i = 0; i <= deg; i++)
		coef[i] = v[i];
}

void polinomio::setDeg(const int& degree){
	deg = degree-1;
	coef = new double[deg+1];
}

double polinomio::value(const double& x){
	double sum = coef[0];
	for (int i=1; i <= deg; i++){
		sum += coef[i] * x;
	}
	
	return sum;
}

polinomio polinomio::derivate(){
	double der [deg+1];
		
	for (int i=0; i<deg; i++)
		der [i] = coef[i+1] * (i+1);
		
	polinomio deriv;
	
	deriv.setDeg(deg);
	deriv.setCoef(der);
	
	return deriv;
}

//OVERLOADING OPERATORI
polinomio polinomio::operator+(const polinomio& original){
	int size = max (deg, original.deg);
	double sum [size];
	int i;
	
	bool notZero = true;
	
	for (i = 0; i<=deg; i++)
		sum [i] = coef[i];
	
	for (i=size; i>=0; i--){
		sum [i] += original.coef[i];
		
		if (sum [i] == 0 && notZero)
			size--;
		else if (sum[i] != 0)
			notZero = false;
	}
	
	polinomio somma;
	
	somma.setDeg(size+1);
	somma.setCoef(sum);
	
	return somma;
}

polinomio polinomio::operator*(const polinomio& original){
	int size = deg + original.deg;
	double prod [size];
	
	for (int i=0; i<=size; i++)
		prod[i] = 0;
	   
	for (int i=0; i<=deg; i++)
     	for (int j=0; j<=original.deg; j++)
         	prod[i+j] += coef[i] * original.coef[j]; 
	
	polinomio molt;
	
	molt.setDeg(size+1);
	molt.setCoef(prod);
	
	return molt;
}

polinomio polinomio::operator*(const double& k){
	double vet [deg+1];
	
	for (int i=0; i<=deg; i++)
	    vet[i] = coef[i] * k;
	        
	polinomio mult;
	
	mult.setDeg(deg+1);
	mult.setCoef(vet);
	
	return mult;
}

polinomio polinomio::operator^(const int& n){
	polinomio power (*this);
	
	for (int i = 0; i<n-1; i++)
		power = power * power;
		
	return power;
}

polinomio polinomio::operator/(const polinomio& original)
{
    double risultato[deg - original.deg]; 
    double app1[deg];//contiene la moltiplicazione tra il risultato trovato dalla divisione e il divisore
    double parz[deg];//risultato parziale
    int max = deg+1;
    int GradMax = (deg - original.deg);//per memorizzazzione risultato
    int l=0;

    risultato[GradMax] = coef[max-1] / original.coef[original.deg];

    for(int y = 0; y<=deg-original.deg; y++)
    {
        for(int i=deg-y,k=original.deg;k>=0; k--,i--)
            app1[i] = (original.coef[k] * risultato[GradMax]) * -1;


        for(int j=deg; j>=0; j--)
        	parz[j] = coef[j] + app1[j];

	    GradMax--;
	    risultato[GradMax] = parz[GradMax+1] / original.coef[original.deg];
	    max--;
    }

    polinomio diviso;

    diviso.setDeg(deg - original.deg + 1);
    diviso.setCoef(risultato);

    return diviso;
}

polinomio polinomio::operator%(const polinomio& original)
{
    double risultato[deg - original.deg]; 
    double app1[deg];//contiene la moltiplicazione tra il risultato trovato dalla divisione e il divisore
    double parz[deg];//risultato parziale
    int max = deg+1;
    int GradMax = (deg - original.deg);//per memorizzazzione risultato
    int l=0;

    risultato[GradMax] = coef[max-1] / original.coef[original.deg];
	
	for(int y=0; y<=deg-original.deg; y++)
    {	
    	for (int i = 0; i <deg; i++)
    		parz [i] = 0;
        
		for(int i=deg-y,k=original.deg; k >= 0; k--,i--)
            app1[i] = (original.coef[k] * risultato[GradMax]) * -1;


        for(int j=0; j < deg-y; j++)
        	parz[j] = coef[j] + app1[j];

	    GradMax--;
	    risultato[GradMax] = parz[GradMax+1] / original.coef[original.deg];
	    max--;
    }

    polinomio resto;

    resto.setDeg(deg);
    resto.setCoef(parz);

    return resto;
}

int main(){
	polinomio a;
	polinomio b;
	polinomio molt;
	polinomio somma;
	polinomio power;
	polinomio div;
	polinomio deriv;
	
	double v [] = {1,-2,1};
	int dim = sizeof(v)/sizeof(*v);
	
	a.setDeg(dim); //Prima set deg per cambiare il grado
	a.setCoef(v);  //Poi set coef per assegnare i coefficenti
	
	double vet [] = {-8,0,-14,0,3};
	dim = sizeof(vet)/sizeof(*vet);
	
	b.setDeg(dim);
	b.setCoef(vet);
	
	molt = a * b;
	somma = a + b;
	power = a ^ 2;
	div = b % a;
	deriv = b.derivate();

	cout << "Polinomio 1\n";
	a.print();
	
	cout << "\n\nPolinomio 2\n";
	b.print();
	
	cout << "\n\nMoltiplicazione\n";
	molt.print();
	
	cout << "\n\nSomma\n";
	somma.print();
	cout << "\nGrado Somma --> " << noshowpos << somma.getDeg();
	
	cout << "\n\nPotenza\n";
	power.print();
	
	cout << "\n\nResto\n";
	div.print();

	cout << "\n\nDerivata\n";
	deriv.print();
	cout << "\nGrado Derivata --> " << noshowpos << deriv.getDeg();
}
