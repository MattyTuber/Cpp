#include<iostream>
class SuperClass {

	public:
	virtual void metodo() {
	
		std::cout << "Sono il metodo della SuperClass" << std::endl;
	}
	
	protected:
	
	int data;
};

class Sub1 : public SuperClass {

	public:
	void metodo() {
	
		std::cout << "Sono il metodo della Subclass1" << std::endl;
	}
};

class Sub2 : public SuperClass {

	public:
	
	void metodo() {
	
		std::cout << "Sono il metodo della Subclass2" << std::endl;
	}
};

int main() {

	SuperClass* SuperPointer;
	
	SuperPointer = new Sub1;
	SuperPointer->metodo();
	
	SuperPointer = new Sub2;
	SuperPointer->metodo();

}
