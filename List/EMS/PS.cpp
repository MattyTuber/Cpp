#include<iostream>
#include<string>
#include<list>

using namespace std;

typedef struct{

	string color;
	int counter;
	int position;

} paziente;


void triage (list<paziente>& lista, paziente element){
	list<paziente>::iterator p;
	
	if(element.color == "Nero"){
		p = lista.end();
		p--;
		
		for(p; p != lista.begin(); p--) {
	
			if((*p).color == "Bianco"){
				if((*p).counter < 12)
					(*p).counter++;
				else
					break;
			}
			
			if((*p).color == "Giallo"){
				if((*p).counter < 6)
					(*p).counter++;
				else
					break;
			}
		
			if((*p).color == "Rosso"){
				if((*p).counter < 3)
					(*p).counter++;
				else
					break;
			}
		
			if((*p).color == "Nero")
				break;
		}
		
		p++;
		lista.insert(p,element);	
	}
	
	if(element.color == "Rosso"){
		p = lista.end();
		p--;
		
		for(p; p != lista.begin(); p--){
	
			if((*p).color == "Bianco"){
				if((*p).counter < 12)
					(*p).counter++;
				else
					break;
			}
			
			if((*p).color == "Giallo"){
				if((*p).counter < 6)
					(*p).counter++;
				else
					break;
			}
		
			if((*p).color == "Rosso")
				break;
		
			if((*p).color == "Nero")
				break;
		}
		
		p++;
		lista.insert(p,element);
	}
	
	
	if(element.color == "Giallo"){
		p = lista.end();
		p--;
		
		for(p; p != lista.begin() ; p--){
	
			if((*p).color == "Bianco"){
				if((*p).counter < 12)
					(*p).counter++;
				else
					break;
			}
			
			if((*p).color == "Giallo")
				break;
			
			if((*p).color == "Rosso")
				break;
		
			if((*p).color == "Nero")
				break;
		}
		
		p++;
		lista.insert(p,element);
	}
	
	if(element.color == "Bianco")
		lista.push_back(element);
}


void print(list<paziente> lista){
	for (auto x : lista){
		cout << "ID --> " << x.position << "\n";
		cout << "Code --> " << x.color << "\n\n";
		cout << "Counter --> " << x.counter << "\n\n";
	}
}

int main(){
	list<paziente> lista;
	paziente patient;
	int count = 1;
	
	cout << "Inserire Codice --> ";
	cin >> patient.color;
	
	patient.counter = 0;
	patient.position = count;
	
	lista.push_back(patient);
	print(lista);
	
	while (true){
		count ++;
		
		cout << "Inserire Codice --> ";
		cin >> patient.color;
		
		patient.counter = 0;
		patient.position = count;
		
		if (patient.color == "00")
			break;
		
		triage(lista, patient);
		print(lista);
	}
	
	return 0;
}
