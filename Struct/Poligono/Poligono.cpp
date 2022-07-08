#include <iostream>

using namespace std;

struct poligono{
	int nlati;
	
	double lato;
};

struct poligono crea(void);
int perimetro(struct poligono perim);
void doppio(struct poligono *pp);

int main()
{
	struct poligono nuovoPoli;
	int perim, duplica;
	
	nuovoPoli = crea();
	
	perim = perimetro(nuovoPoli);
	
	doppio (&nuovoPoli);
	
	cout << "Perimetro --> " << perim << endl;
	
	cout << "Doppio del lato --> " << nuovoPoli.lato;
	
	return 0;
}

struct poligono crea(void)
{
	struct poligono input;
	
	cout << "Inserire il numero di lati --> ";
	cin >> input.nlati;
	
	cout << "Inserire dimensione lati --> ";
	cin >> input.lato;
	
	return input;
}

int perimetro(struct poligono perim)
{	
	return perim.lato * perim.nlati;
}

void doppio(struct poligono *pp)
{
	(*pp).lato = (*pp).lato * 2;
}
