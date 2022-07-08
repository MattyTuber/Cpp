#include <iostream>

using namespace std;

class data{
	public:
		data(int giorno, int mese, int anno); //Constructor
		data(const data& original); //Copy
		bool operator<(const data& original);//Operator
		~data(){}
		
		void stampa();
		void imposta(int giorno, int mese, int anno);
		
				
	private:
		int day, month, year;	
};

data::data(int giorno, int mese, int anno){
	day = giorno;
	month = mese;
	year = anno;
}

data::data(const data& original){
	day = original.day;
	month = original.month;
	year = 	original.year;
}

bool data::operator<(const data& original){
	if (year >= original.year)
		if (month >= original.month)
			if (day >= original.day)
				return true;
	
	return false;
}

void data::stampa(){
	cout << day << "/" << month << "/" << year << "\n";
}

void data::imposta(int giorno, int mese, int anno){
	day = giorno;
	month = mese;
	year = anno;
}

int main(){
	data teo (14, 01, 2003);
	data ale (teo);
	
	cout << "Teo --> ";
	teo.stampa();
	
	cout << "Ale --> ";
	ale.stampa();
	
	ale.imposta(19, 12, 2003);
	cout << "\nAle --> ";
	ale.stampa();
	
	if (ale < teo)
		cout << "\n\nTeo is the best"; // Data più lontana
	else
		cout << "\n\nAle is the best";
		
	return 0;
}
