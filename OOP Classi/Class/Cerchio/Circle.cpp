#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class cerchio{
	public:
		cerchio(double raggio){
			radius = raggio;
		}
		~cerchio(){}
		
		double getRadius();
		double getPerimeter();
		double getArea();
		
	private:
		double radius;
};

double cerchio::getRadius(){
	return radius;
}

double cerchio::getPerimeter(){
	return 2 * M_PI * radius;
}

double cerchio::getArea(){
	return M_PI * pow(radius, 2);
}

void maxCircle(cerchio a, cerchio b){
	if (a.getArea() > b.getArea())
		cout << "\n\nCerchio Maggiore --> Primo";
	else
		cout << "\n\nCerchio Maggiore --> Secondo";
}

int main(){
	double r;
	
	cout << "Inserire Raggio --> ";
	cin >> r;
	cerchio circle (r);
	
	cout << "Inserire Raggio --> ";
	cin >> r;
	cerchio circle2 (r);
	
	cout << "\nRaggio --> " << circle.getRadius();
	cout << "\n\nPerimetro --> " << circle.getPerimeter();
	cout << "\n\nArea --> " << circle.getArea();
	
	maxCircle(circle, circle2);
	
	return 0;
}
