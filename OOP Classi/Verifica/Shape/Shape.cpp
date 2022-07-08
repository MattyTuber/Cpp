#include <iostream>
#include <string>

using namespace std;

class shape{
	public:
		shape(double a){
			area = a;
		}
		
		double getArea(){
			return area;
		}
		
	protected:
		double area;
};

class circle : public shape{
	public:
		circle(double a, string c):shape(a){
			color = c;
		}
		
		string getColor(){
			return color;
		}
		
	private:
		string color;
};

int main(){
	circle cerchio(4, "Verde");
	
	cout << "Area --> " << cerchio.getArea();
	cout << "\nColore --> " << cerchio.getColor();
}
