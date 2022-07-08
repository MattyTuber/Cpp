#include <iostream>

using namespace std;

int gcd(int a, int b){
	if (a == 0)
		return b;
	
	return gcd(b%a, a);
}

class frazione{
	public:
		frazione (int n, int d);
		frazione ();
		frazione (const frazione& original);
		
		frazione operator+(const frazione& original);
		
		void mult (int num);
		double dec ();
		
		void print();
	
	private:
		int N, D;	
};

frazione::frazione(int n, int d){
	N = n;
	D = d;
}

frazione::frazione(){
	N = 1;
	D = 2;
}

frazione::frazione(const frazione& original){
	N = original.N;
	D = original.D;
}

frazione frazione::operator+(const frazione& original){
	int den;
	int num;
	
	den = gcd (D, original.D);
	den = (D * original.D) / den;
	
	num = N * (den/D) + original.N * (den / original.D);
	
	frazione sum (num, den);
	
	return sum;
}

void frazione::mult(int num){
	N = N * num;
}

double frazione::dec(){
	double d = double(N) / double(D);
	return d;
}

void frazione::print(){
	cout << N << "/" << D;
}

int main(){
	frazione A (5, 2);
	frazione B (1, 2);
	
	frazione C = A + B;
	
	cout << "Decimale A --> " << A.dec() << endl;
	cout << "Decimale B --> " << B.dec();
	
	cout << "\n\n";
	A.print();
	cout << " + ";
	B.print();
	cout << " = ";
	C.print();
	
	return 0;
}
