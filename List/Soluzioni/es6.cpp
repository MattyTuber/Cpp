#include<iostream>
#include<string>
#include<list>

typedef struct{

	std::string color;
	int counter;
	int position;

} paziente;


void upgrade_list (std::list<paziente>& lista, paziente element ){

	std::list<paziente>::iterator p;
	if(element.color == "nero"){
	
		p = lista.end();
		p--;
		
		for(p = p ; p != lista.begin() ; p--) {
	
			if((*p).color == "bianco" ){
			
				if((*p).counter < 12) (*p).counter ++ ;
				else  break;
			}
			if((*p).color == "giallo" ){
			
				if((*p).counter < 6) (*p).counter ++ ;
				else break;
			}
		
			if((*p).color == "rosso" ){
			
				if((*p).counter < 3) (*p).counter ++ ;
				else break;
			}
		
			if((*p).color == "nero" ){
			
				break;
				
			}
		}
	
			p++;
			lista.insert(p,element);
		
	}
	
	if(element.color == "rosso"){
	
		p = lista.end();
		p--;
		
		for(p = p ; p != lista.begin() ; p--) {
	
			if((*p).color == "bianco" ){
			
				if((*p).counter < 12) (*p).counter ++ ;
				else  break;
			}
			if((*p).color == "giallo" ){
			
				if((*p).counter < 6) (*p).counter ++ ;
				else break;
			}
		
			if((*p).color == "rosso" ){
			
				 break;
			}
		
			if((*p).color == "nero" ){
			
				break;
				
			}
		}
		
			p++;
			lista.insert(p,element);
		
	}
	
	
	if(element.color == "giallo"){
	
		p = lista.end();
		p--;
		
		for(p = p ; p != lista.begin() ; p--) {
	
			if((*p).color == "bianco" ){
			
				if((*p).counter < 12) (*p).counter ++ ;
				else  break;
			}
			if((*p).color == "giallo" ){
			
				break;
			}
		
			if((*p).color == "rosso" ){
			
				 break;
			}
		
			if((*p).color == "nero" ){
			
				break;
				
			}
		}
		
			p++;
			lista.insert(p,element);
		
	}
	
	
	if(element.color == "bianco") {
			lista.push_back(element);
	}
}


void print_list(std::list<paziente> lista ) {

	std::list<paziente>::iterator p;
	
	for(p = lista.begin(); p != lista.end(); p++) {
		
	
		std::cout<< "colore:  " << (*p).color  << "\t numero: "<< (*p).position << "\t sorpassi: " << (*p).counter <<  std::endl; 
	}

}
int main() {

	std::list<paziente> lista;
	paziente app;
	int count = 1;
	std::cout << "Inseire colore paziente" << std:: endl;
	std::cin >> app.color;
	app.counter = 0;
	app.position = count;
	lista.push_back(app);
	print_list(lista);
	
	while (true) {
	
		count ++;
		std::cout << "Inseire colore paziente" << std:: endl;
		std::cin >> app.color;
		app.counter = 0;
		app.position = count;
		
		upgrade_list(lista, app);
		print_list(lista);

	}
}
