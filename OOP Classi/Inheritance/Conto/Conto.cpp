#include <iostream>

using namespace std;

class conto{
	public:
		conto(){
			saldo = 0;
		}
	protected:
		double saldo;
};

class cc : public conto{
	public:
		cc():conto(){}
		
		void versa(double cash){
			saldo += cash;
		}
		
		void preleva(double cash){
			saldo -= cash;
		}
		
		void mostra(){
			cout << "Saldo --> " << saldo << "\n";
		}
};

int main(){
	cc bank;
	
	bank.versa(300);
	bank.mostra();
	
	bank.preleva(100);
	bank.mostra();
	
	return 0;
}
