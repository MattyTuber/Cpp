#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char a, b;
	int x, count = 0;

	cout << "Inserire un carattere --> ";
	cin >> a;

	cout << "Inserire un secondo carattere --> ";
	cin >> b;

	x = a ^ b;

	cout << "Xor --> " << x << endl;

	while (x!=0)
	{
		if ((x & 1) == 1)
			count++;

		x = x >> 1;
	}

	cout << "I due caratteri hanno distanza --> " << count;
	
	return 0;
}