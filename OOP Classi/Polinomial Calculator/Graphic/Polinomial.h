#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class polinomio
{
public:
	// CONSTRUCTORS AND DESTRUCTOR
	polinomio(int grado){
		deg = grado;
		coef = new double[deg + 1];
	}

	polinomio(){
		deg = 0;
		coef = new double[1];
		coef[0] = 1;
	}

	polinomio(const polinomio &original){
		deg = original.deg;
		coef = original.coef;
	}

	~polinomio() {}

	//METODI GET
	int getDeg(){
		return deg;
	}

	//METODI
	void fill();
	void print();

	void setCoef(const double *v);
	void setDeg(const int &degree);

	double value(const double &x);
	polinomio derivate();

	//OVERLOADING OPERATORI
	void operator=(const polinomio &original)
	{
		deg = original.deg;
		coef = original.coef;
	}

	polinomio operator+(const polinomio &original);
	polinomio operator*(const polinomio &original);
	polinomio operator*(const double &k);
	polinomio operator^(const int &n);
	polinomio operator/(const polinomio &original);
	polinomio operator%(const polinomio &original);

private:
	int deg;
	double *coef;
};

void polinomio::fill()
{
	for (int i = 0; i < deg + 1; i++)
	{
		cout << " - Inserire Coefficiente " << noshowpos << i << " Grado --> ";
		cin >> polinomio::coef[i];
	}
}

void polinomio::print()
{
	cout << "\n\t\t\t\t - [ ";
	for (int i = deg; i >= 0; i--)
	{
		if (coef[i] == 0)
			continue;
			
		if (i == 0)
			cout << showpos << coef[i];
		else if (i == 1)
			if (coef [i] == 1)
				cout << " + x ";
			else
				cout << showpos << coef[i] << " x ";
		else
			if (coef [i] == 1)
				cout << " + x^" << noshowpos << i << " ";
			else
				cout << showpos << coef[i] << " x^" << noshowpos << i << " ";
	}
	cout << " ] -";
}

void polinomio::setCoef(const double *v)
{
	for (int i = 0; i <= deg; i++)
		coef[i] = v[i];
}

void polinomio::setDeg(const int &degree)
{
	deg = degree - 1;
	coef = new double[degree];
}

double polinomio::value(const double &x)
{
	double sum = coef[0];
	for (int i = 1; i <= deg; i++)
	{
		sum += coef[i] * pow(x, i);
	}

	return sum;
}

polinomio polinomio::derivate()
{
	double der[deg];

	for (int i = 0; i < deg; i++)
		der[i] = coef[i + 1] * (i + 1);

	polinomio deriv;

	deriv.setDeg(deg);
	deriv.setCoef(der);

	return deriv;
}

//OVERLOADING OPERATORI
polinomio polinomio::operator+(const polinomio &original)
{
	int size = max(deg, original.deg);
	double sum[size];
	int i;

	bool notZero = true;

	for (i = 0; i <= size; i++)
		sum[i] = 0;

	for (i = 0; i <= deg; i++)
		sum[i] = coef[i];

	for (i = size; i >= 0; i--)
	{
		sum[i] += original.coef[i];

		if (sum[i] == 0 && notZero)
			size--;
		else if (sum[i] != 0)
			notZero = false;
	}

	polinomio somma;

	somma.setDeg(size + 1);
	somma.setCoef(sum);

	return somma;
}

polinomio polinomio::operator*(const polinomio &original)
{
	int size = deg + original.deg;
	double prod[size];

	for (int i = 0; i <= size; i++)
		prod[i] = 0;

	for (int i = 0; i <= deg; i++)
		for (int j = 0; j <= original.deg; j++)
			prod[i + j] += coef[i] * original.coef[j];

	polinomio molt;

	molt.setDeg(size + 1);
	molt.setCoef(prod);

	return molt;
}

polinomio polinomio::operator*(const double &k)
{
	double vet[deg + 1];

	for (int i = 0; i <= deg; i++)
		vet[i] = coef[i] * k;

	polinomio mult;

	mult.setDeg(deg + 1);
	mult.setCoef(vet);

	return mult;
}

polinomio polinomio::operator^(const int &n)
{
	polinomio power(*this);
	polinomio app(power);

	for (int i = 0; i < n - 1; i++)
		app = app * power;

	return app;
}

polinomio polinomio::operator/(const polinomio &original)
{
	double risultato[deg - original.deg];
	double app1[deg];
	double parz[deg];
	int max = deg;
	int GradMax = (deg - original.deg);
	int l = 0;

	polinomio diviso;

	if (original.deg > deg)
	{
		diviso.setDeg(deg + 1);
		diviso.setCoef(coef);

		return diviso;
	}

	for (int i = 0; i <= deg; i++)
		app1[i] = 0;

	for (int i = 0; i <= deg; i++)
		parz[i] = coef[i];

	risultato[GradMax] = coef[max] / original.coef[original.deg];

	for (int y = 0; y <= deg - original.deg; y++)
	{
		for (int i = deg - y, k = original.deg; k >= 0; k--, i--)
			app1[i] = (original.coef[k] * risultato[GradMax]) * -1;

		for (int j = deg; j >= 0; j--)
			parz[j] = parz[j] + app1[j];

		app1[deg - y] = 0;

		GradMax--;
		max--;
		risultato[GradMax] = parz[max] / original.coef[original.deg];
	}

	diviso.setDeg(deg - original.deg + 1);
	diviso.setCoef(risultato);

	return diviso;
}

polinomio polinomio::operator%(const polinomio &original)
{
	double risultato[deg - original.deg];
	double app1[deg];
	double parz[deg];
	int max = deg;
	int GradMax = (deg - original.deg);
	int l = 0;

	polinomio resto;

	for (int i = 0; i <= deg; i++)
		app1[i] = 0;

	for (int i = 0; i <= deg; i++)
		parz[i] = coef[i];

	if (original.deg > deg)
	{
		resto.setDeg(1);
		resto.setCoef(app1);

		return resto;
	}

	risultato[GradMax] = coef[max] / original.coef[original.deg];

	for (int y = 0; y <= deg - original.deg; y++)
	{
		for (int i = deg - y, k = original.deg; k >= 0; k--, i--)
			app1[i] = (original.coef[k] * risultato[GradMax]) * -1;

		for (int j = deg; j >= 0; j--)
			parz[j] = parz[j] + app1[j];

		app1[deg - y] = 0;

		GradMax--;
		max--;
		risultato[GradMax] = parz[max] / original.coef[original.deg];
	}

	resto.setDeg(deg);
	resto.setCoef(parz);

	return resto;
}
