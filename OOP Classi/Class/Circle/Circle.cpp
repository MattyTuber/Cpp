#include <iostream>

using namespace std;

class cerchio{
	public:
		float raggio;
		
		cerchio(float raggio); //Constructor
		~cerchio(); //Destructor
		
		cerchio(const cerchio& original);
		
		float getRadius();
	
	private:
		float r;
};

cerchio::cerchio(float raggio){
	r = raggio;
}

cerchio::cerchio(const cerchio& original){
	r = original.r;
}

cerchio::~cerchio(){
	;
}

float cerchio::getRadius(){
	return r;
}

int main()
{
	cerchio circle(1.5);
	cerchio circle1(circle);
	
	cout << "Raggio --> " << circle.getRadius() << endl;
	cout << "Raggio1 --> " << circle1.getRadius();
}
