#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string a, b;
	int x, count = 0;

	cout << "Inserire una stringa --> ";
	getline (cin, a);

	cout << "Inserire una seconda stringa --> ";
	getline (cin, b);

	x = a ^ b;

	cout << "Xor --> " << x << endl;

	while (x!=0)
	{
		if ((x & 1) == 1)
			count++;

		x = x >> 1;
	}

	cout << "Le due stringhe hanno distanza --> " << count;
	
	return 0;
}