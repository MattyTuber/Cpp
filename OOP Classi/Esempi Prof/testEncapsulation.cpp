/*
c++ -o testEncapsulation testEncapsulation.cpp
*/

#include <iostream>
#include <cmath>

class vect2d
{
public:
  vect2d(double x, double y)
  {
    x_p = x;
    y_p = y;
  }

  ~vect2d()
  {
   std::cout << "I'm the "
	      << "destructor"
	      << std::endl;
  }
 
  double modulus()
  {
    return sqrt(x_p*x_p + y_p*y_p);
  }
  
private:
  double x_p;
  double y_p;
};

int main ()
{
  vect2d v(1,2);
  
  std::cout << "Modulo: " << v.modulus() << std::endl;
  
  return 0;
}
