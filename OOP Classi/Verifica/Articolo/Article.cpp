#include <iostream>
#include <string>

using namespace std;

class articolo{
	public:
		articolo(string p, double prezzo){
			product = p;
			price = prezzo;
		}
		
		void sconto(){
			price = price - price * 10 / 100;
		}
		
	protected:
		string product;
		double price;
};

class abito : public articolo{
	public:
		abito(string p, double prezzo, string taglia):articolo(p, prezzo){
			size = taglia;
		}
		
		void sconto(){
			price = price - price * 20 / 100;
		}
		
		double getPrice(){
			return price;
		}
		
	private:
		string size;
};

int main(){
	abito felpa("Felpa", 30, "S");
	
	cout << "Prezzo --> " << felpa.getPrice();
	
	felpa.sconto();
	cout << "\nPrezzo Scontato --> " << felpa.getPrice();
}
