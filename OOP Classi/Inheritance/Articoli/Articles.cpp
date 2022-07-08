#include <iostream>
#include <string>

#define TODAY 2021

using namespace std;

class articolo{
	public:
		articolo(string codice, double prezzo);
		~articolo(){}
		
		void sconta();
		
		string getCode();
		double getPrice();
		
	protected:
		string code;
		double price;
};

class alimentare : public articolo{
	public:
		alimentare (string codice, double prezzo, int anno) : articolo (codice, prezzo){
			year = anno;
		}
		
		void sconto();
	
	private:
		int year;
};

articolo::articolo(string codice, double prezzo){
	code = codice;
	price = prezzo;
}

string articolo::getCode(){
	return code;
}

double articolo::getPrice(){
	return price;
}

void articolo::sconta(){
	price = price - price / 100 * 5;
}

void alimentare::sconto(){
	if (year == TODAY)
		price = price - price / 100 * 20;
}

int main()
{
	alimentare banane ("12fsf324", 2.30, 2021);
	alimentare burro ("f6d5s4f6ds51", 1.50, 2020);
	articolo munna ("5da56as4f", 169.69);
	
	banane.sconto();
	burro.sconto();
	munna.sconta();
	
	cout << "Alimento --> " << banane.getCode() << endl;
	cout << "Prezzo --> " << banane.getPrice();
	
	cout << "\n\nAlimento --> " << burro.getCode() << endl;
	cout << "Prezzo --> " << burro.getPrice();
	
	cout << "\n\nAlimento --> " << munna.getCode() << endl;
	cout << "Prezzo --> " << munna.getPrice();
	
	cout << "\n\nTotale --> " << banane.getPrice() + burro.getPrice() + munna.getPrice();
	
	return 0;
}
