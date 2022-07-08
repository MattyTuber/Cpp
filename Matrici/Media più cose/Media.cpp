#include <iostream>
#include <cstdlib>

#define NR 3
#define NC 3

using namespace std;

int main()
{
	int i, j, somma = 0, pos = 0, neg = 0;
	int mat [NR] [NC];
	float media;

	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			cout << "Inserire un valore --> ";
			cin >> mat [i] [j];
		}
	}

	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			somma = somma + mat [i] [j];
		}
	}

	system ("cls");

	media = static_cast <float> (somma) / (NR * NC);

	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			mat [i] [j] = mat [i] [j] - media;

			cout << mat [i] [j] << "\t";
		}

		cout << "\n\n\n";
	}

	cout << "Positivo o Negativo" << "\n\n\n\n";

	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			if (mat [i] [j] > 0)
			{
				mat [i] [j] = 1;
				pos++;
			}
			else
			{
				mat [i] [j] = 0;
				neg++;
			}
		}
	}

	cout << "I numeri positivi sono --> " << pos << endl;
	cout << "I numeri negativi sono --> " << neg << endl;

	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{
			cout << mat [i] [j] << "\t";
		}

		cout << "\n\n\n";
	}

	return 0;
}