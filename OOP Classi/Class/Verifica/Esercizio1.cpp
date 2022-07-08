#include <iostream>
#include <string>

using namespace std;

class automobile{
	public:
		automobile(string modello, string targa, int anno);
		~automobile(){}
		
		void printModel();
		void printPlate();
		int getYear();
		
	private:
		string model, plate;
		int year;
};

automobile::automobile(string modello, string targa, int anno){
	model = modello;
	plate = targa;
	year = anno;
}

void automobile::printModel(){
	cout << "Modello --> " << model << endl;
}

void automobile::printPlate(){
	cout << "Targa --> " << plate << endl;
}

int automobile::getYear(){
	return year;
}

int main(){
	string mod, pl;
	int an;
	
	cout << "Inserire Modello --> ";
	cin >> mod;
	
	cout << "Inserire Targa --> ";
	cin >> pl;
	
	cout << "Inserire Anno --> ";
	cin >> an;
	
	automobile a (mod, pl, an);
	
	cout << "\n\n";
	a.printModel();
	a.printPlate();
	cout << "Anno --> " << a.getYear();
}
