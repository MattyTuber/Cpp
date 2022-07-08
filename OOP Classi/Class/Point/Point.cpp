#include <iostream>
#include <cmath>

using namespace std;

class point {
	public:		
		point ();
		~point ();
		
		void setV();
		void setPos();
		
	private:
		float xP, yP;
		float vxP, vyP;
		
};

point::point()
{
	;
}

point::~point()
{
	;
}

void point::setV()
{
	vxP = rand() / (1. * RAND_MAX) - rand() / (1. * RAND_MAX);
	vyP = rand() / (1. * RAND_MAX) - rand() / (1. * RAND_MAX);
}

//TODO: controllare e implementare nel programma in un modo diverso

void point::setPos(){

		x_p = x_p + vx_p * delta;
		y_p = y_p + vy_p * delta; 
}

int main()
{
	
	return 0;
}

