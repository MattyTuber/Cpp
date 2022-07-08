#include <iostream>

using namespace std;

class poligono{
	public:
		poligono(double lati);
		~poligono(){}
		
		int getLati();
	
	protected:
		double side;
};

poligono::poligono(double lati){
	side = lati;
}

int poligono::getLati(){
	return side;
}

class quadrato : public poligono{
	public:
		quadrato (double lati) : poligono (lati){}
		
		double getArea();
		double getPerimeter();
};

double quadrato::getArea(){
	return side * side;
}

double quadrato::getPerimeter(){
	return side * 4;
}

int main(){
	poligono polygon (5);
	quadrato square (2.5);
	
	cout << "Lati Poligono --> " << polygon.getLati();
	cout << "\n\nArea Quadrato --> " << square.getArea() << endl;
	cout << "Perimetro Quadrato --> " << square.getPerimeter();
}
