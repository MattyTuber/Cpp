#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, i, bud, max, min, id_1, id_2;

	cout << "Inserire il numero di laptop --> ";
	cin >> N;

	int vett[N];

	for (i = 0; i < N; ++i)
	{
		cout << "Inserire il prezzo del laptop " << i+1 << " --> ";
		cin >> vett[i];
	}

	cout << "Inserire il budget --> ";
	cin >> bud;

	max = vett[0];
	min = vett[N];

	for (i = 0; i < N; ++i)
	{
		if (vett[i] <= bud)
		{
			cout << "Il laptop " << i+1 << " costa " << vett[i] << " euro" << endl;

			if (vett[i] > max)
			{
				max = vett[i];
				id_1 = i+1;
			}
		}
		else
		{
			if (vett[i] < min)
			{
				min = vett[i];
				id_2 = i+1;
			}
		}	
	}

	cout << "Piu' costoso entro il budget --> Laptop -> " << id_1 << " Prezzo -> " << max << " euro" << endl;

	cout << "Meno costoso --> Laptop -> " << id_2 << " Prezzo -> " << min << " euro" << endl;

	return 0;
}