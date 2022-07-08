#include <iostream>
#include <cstdlib>

using namespace std;

void primo (int num);

int main(int argc, char *argv[])
{
	cout << "Benvenuto nel programma " << argv[0] << endl;
	
	int num = 0;
	
	if (argc == 1) {
		cout << "Inserire un numero --> ";
		cin >> num;
	}
	else {
		num = atoi (argv [1]);
	}
	
	primo (num);
	
	return 0;
}

void primo(int n)
{
	int i, j, cont;
	
	for (i=1; i<=n; i++)
	{
		cont = 0;
		
		for (j=1; j<=n; j++)
		{
			if (i % j == 0)
				cont++;
		}
		if (cont == 2)
		{
			cout << i << "\t";
		}
	}
}
