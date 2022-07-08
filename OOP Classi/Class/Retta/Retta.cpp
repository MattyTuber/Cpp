#include <iostream>

using namespace std;

class retta {
	public:
		retta (int m, int q);
		~retta ();
		
		int getM();
		int getQ();
		
		void print();
		void normal();
		
	private:
		int ang;
		int inter;
};

retta::retta(int m, int q){
	ang = m;
	inter = q;
}

retta::~retta(){
	;
}

int retta::getM(){
	return ang;
}

int retta::getQ(){
	return inter;
}

void retta::print(){
	cout << showpos << ang * -1 << "x" << " + y " << showpos << inter * -1 << " = 0";
}

void retta::normal(){
	cout << "y = " << showpos << ang << "x " << showpos << inter;
}

void parallel (retta line, retta line2){
	if (line.getM() == line2.getM())
		cout << "\n\nLe Rette sono parallele";
	else
		cout << "\n\nLe Rette non sono parallele";
}
	
int main()
{
	int co_ang, inte;
	
	cout << "Inserire Coefficiente Angolare --> ";
	cin >> co_ang;
	
	cout << "Inserire Intercetta --> ";
	cin >> inte;
	
	retta line (co_ang, inte);
	
	//Retta 2
	cout << "Inserire Coefficiente Angolare --> ";
	cin >> co_ang;
	
	cout << "Inserire Intercetta --> ";
	cin >> inte;
	
	retta line2 (co_ang, inte);
	
	cout << "\nRetta 1 --> \n";
	
	line.print();
	cout << "\n";
	line.normal();
	
	cout << "\n\nRetta 2 --> \n";
	
	line2.print();
	cout << "\n";
	line2.normal();
	
	parallel (line, line2);
	
	return 0;
}

