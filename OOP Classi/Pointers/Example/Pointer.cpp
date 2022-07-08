#include<iostream>

using namespace std;

class Super {
	public: 

		void metodo1 () {
			cout << "Sono il metodo della SuperClass" << endl;
		}
};


class Sub : public Super {
	public: 

		void metodo1 () {
			cout << "Sono il metodo della SubClass" << endl;
		}
};
int main() {
	Sub SubObject;
	Super SuperObject;	
	
	Super *Object = &SubObject;
	
	Object->metodo1();
}
