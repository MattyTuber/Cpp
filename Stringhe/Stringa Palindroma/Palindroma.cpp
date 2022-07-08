#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	char a [256];
	string b, a1;
	int len, i;

	cout << "Inserire una stringa --> ";
	gets (a);
	
	len = static_cast <int> (strlen(a));
   	
	for (i=0; i < len; i++)
      	a [i] = static_cast <char> (tolower(a [i]));
	
	a1 = a;
	
	cout << "Stringa --> " << a1 << endl;

	b = static_cast <string> (strrev (a));
	
	cout << "Contrario --> " << b << endl;
	
	if (a1 == b)
		cout << "Palindromo";
	else
		cout << "Non Palindroma";

	return 0;
}
