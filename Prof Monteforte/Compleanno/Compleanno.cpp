#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main()
{
	char nome [50];
	
	cout << "Inserire il nome --> ";
	cin >> nome;
	
	cout << "Inserire le date nel formato dd/mm/yyyy" << endl;
	
	char day[3], month[3], year[5];
	
	cout << "Inserire data di compleanno --> ";
	
	cin.get(day, 3, '/');
	cin.ignore(100, '/');
	
	cin.get(month, 3, '/');
	cin.ignore(100, '/');
	
	cin.get(year, 5);
	
	int d, m, y;
	
	d = atoi(day);
	m = atoi(month);
	y = atoi(year);
	
	char day1[3], month1[3], year1[5];
	
	cout << "Inserire data di oggi --> ";
	
	cin.get(day1, 3, '/');
	cin.ignore(100, '/');
	
	cin.get(month1, 3, '/');
	cin.ignore(100, '/');
	
	cin.get(year1, 5);
	
	int d1, m1, y1;
	
	d1 = atoi(day1);
	m1 = atoi(month1);
	y1 = atoi(year1);
	
	if (d == d1 && m == m1)
		cout << "Auguri Dude!!";
}
