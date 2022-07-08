#include <iostream>
#include <string>

using namespace std;

class libro{
	public:
		libro(string titolo, string editore, double prezzo);
		~libro(){}
		
		string getTitle();
		string getEditor();
		double getPrice();
		
	protected:
		string title;
		string editor;
		double price;
};

class rivista : public libro{
	public:
		rivista (string titolo, string editore, double prezzo, string frequenza) : libro (titolo, editore, prezzo){
			frequency = frequenza;
		}
		
		string getFrequency();
		
	private:
		string frequency;
};

libro::libro(string titolo, string editore, double prezzo){
	title = titolo;
	editor = editore;
	price = prezzo;
}

string libro::getTitle(){
	return title;
}

string libro::getEditor(){
	return editor;
}

double libro::getPrice(){
	return price;
}

string rivista::getFrequency(){
	return frequency;
}

int main()
{
	libro a ("Ghost in The Wires", "Back Bay Books", 9.99);
	rivista b ("Wired", "Nicholas Thompson", 2.99, "Mensile");
	
	
	cout << "Libro" << endl;
	cout << "Titolo --> " << a.getTitle() << endl;
	cout << "Editore --> " << a.getEditor() << endl;
	cout << "Prezzo --> " << a.getPrice();
	
	cout << "\n\nRivista" << endl;
	cout << "Titolo --> " << b.getTitle() << endl;
	cout << "Editore --> " << b.getEditor() << endl;
	cout << "Prezzo --> " << b.getPrice() << endl;
	cout << "Frequenza --> " << b.getFrequency();
	
	return 0;
}
