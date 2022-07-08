#include <iostream>
class SuperClass {

	public:

		void Metodo() {

			std::cout << "Sono il metodo della superclass" << std::endl;

		}
};

class SubClass : public SuperClass {

	public:

		void Metodo() {

			std::cout << "Sono il metodo della subclass" << std::endl;

		}

};

int main () {

	SubClass subobject;

	subobject.Metodo(); //Richiama il metodo della SubClass
	
	subobject.SuperClass::Metodo(); //Richiama il metodo della SuperClass

	SuperClass* ptr = &subobject;

	ptr->Metodo();
	
}
