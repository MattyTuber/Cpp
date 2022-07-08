#include <iostream>

using namespace std;

class quadrato {
	public:
		float lato;
		float area, perimetro;
		
		quadrato (float lato);
		~quadrato ();
		
		float surface ();
		float perimeter ();
		
	private:
		float lat;
};

quadrato::quadrato(float lato)
{
	lat = lato;	
}

quadrato::~quadrato()
{
	;
}

float quadrato::surface()
{
	area = lat * lat;
	
	return area;
}

float quadrato::perimeter()
{
	perimetro = lat * 4;
	
	return perimetro;
}

void dim (quadrato square, quadrato square2)
{ 
	if (square.surface() > square2.surface())
		cout << "Il Primo Quadrato e' Maggiore";
	else
		cout << "Il Secondo Quadrato e' Maggiore";
}
	
int main()
{
	quadrato square (1.58);
	quadrato square2 (2.5);
	
	dim (square, square2);
	
	return 0;
}

