#include <iostream>

using namespace std;

class punto{
	public:
		double x;
		double y;
		
		punto (double x, double y);
		~punto ();
		
	private:
		double x_p;
		double y_p;
};

punto::punto(double x, double y)
{
	cout << "Sono il Costruttore" << endl;
	x_p = x;
	y_p = y;
}

punto::~punto()
{
	cout << "Sono il Distruttore" << endl;
}

int main()
{
	punto point(2.365, 1.420);
	
	cout << "\nX --> " << point.x << endl;
	cout << "Y --> " << point.y << endl << endl;
	
	return 0;
}
