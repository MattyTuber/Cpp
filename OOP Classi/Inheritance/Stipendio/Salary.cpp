#include <iostream>

using namespace std;

class dependant{
	public:
		dependant(double stipendio){
			salary = stipendio;
		}
		
		double getSalary(){
			return salary;
		}
		
		void setSalary(double s){
			salary = s;
		}
		
	protected:
		double salary;
};

class worker : public dependant{
	public:
		worker (double stipendio) : dependant (stipendio){}
};

class employee : public dependant{
	public:
		employee (double stipendio) : dependant (stipendio){}
};

class director : public dependant{
	public:
		director (double stipendio) : dependant (stipendio){}
};

int main(){
	worker p1(1500);
	cout << "Stipendio --> " << p1.getSalary();
	p1.setSalary(1460.9);
	cout << "\n\nStipendio --> " << p1.getSalary();
	
	return 0;
}
