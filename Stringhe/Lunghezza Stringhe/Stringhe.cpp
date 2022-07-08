#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string a, b;

	cout << "Inserire una stringa --> ";
	getline (cin, a);

	cout << "Inserire una seconda stringa --> ";
	getline (cin, b);

	if (a.size() >= b.size())
		cout << a;
	else
		cout << b;
		
	return 0;
}
