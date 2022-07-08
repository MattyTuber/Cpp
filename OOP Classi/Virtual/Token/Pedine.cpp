#include <iostream>
#include <string>

using namespace std;

class pedina{
	public:
		pedina (string colore){
			color = colore;
		}
		
		string getColor(){
			return color;
		}
		
		virtual void help(){}
		
	protected:
		string color;
};

class cavallo : public pedina{
	public:
		cavallo (string colore):pedina(colore){}
		
		void help(){
			cout << "Cavallo\n";
		}
};

class alfiere : public pedina{
	public:
		alfiere (string colore):pedina(colore){}
		
		void help(){
			cout << "Alfiere\n";
		}
};

class torre : public pedina{
	public:
		torre (string colore):pedina(colore){}
		
		void help(){
			cout << "Torre\n";
		}
};

int main(){	
	cavallo c ("Bianco");
	alfiere a ("Nero");
	torre t ("Bianco");
	
	pedina *token;
	
	int choice;
	
	cout << "Scelta --> ";
	cin >> choice;
	
	switch(choice){
		case 1:
			token = &c;
			token->help();
			cout << "Colore --> " << token->getColor();
		break;
		
		case 2:
			token = &a;
			token->help();
			cout << "Colore --> " << token->getColor();
		break;
		
		case 3:
			token = &t;
			token->help();
			cout << "Colore --> " << token->getColor();
		break;
	}
}
