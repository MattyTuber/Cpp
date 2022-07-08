#include <iostream>

using namespace std;

void primo (int num);

int main()
{
	
	int num;
	
	cout << "Inserire un numero --> ";
	cin >> num;
	
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
