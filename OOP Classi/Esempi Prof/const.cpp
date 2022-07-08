#include<iostream>

using namespace std;
int main()
{
	/*intero costante*/
	const int i=10;
	
	// i=20; non posso farlo

	cout << i << endl;
	
	/* puntatore a intero costante */

	int a = 20;
	
	const int* j=&a ;
	
	// *j=0; non posso farlo

	j=&i; //posso farlo perche' e' il contenuto del puntatore a essere costante
	
	

	cout << &j << endl;
	
	cout << *j << endl;
	
	cout << j << endl;


	/*puntatore costante a intero variabile*/


	int b=0;
	int* const k = &b;

	// k=&i; non si puo' fare
	
	*k=10;

	cout << &k << endl;
	
	cout << *k << endl;
	
	cout << k << endl;

	/*puntatore costante a  intero costante*/

	int const* const m (&a);	
}
