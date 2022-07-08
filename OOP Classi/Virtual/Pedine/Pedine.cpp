#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Token{
	public:
		virtual void Attack(){}
	protected:
		double damage;
		double health;
};

class Archery: public Token{	//lanciato una freccia
	public:
		Archery (){
			damage = 1;
			health = 10;
		}
		
	void Attack();
};

class Swordman: public Token{	//tirato un fendente e perso 5% vita
	public:
		Swordman (){
			damage = 5;
			health = 8;
		}
		
	void Attack();
};

void Archery::Attack(){
	cout<<"Lanciato una freccia\n\n";
}

void Swordman::Attack(){
	cout<<"Tirato un fendente\n\n";
	
	double perc = health * 1. * (5/100);
	health = health - perc;
}

int main (){
	int app;
	Token *pedina;
	
	cout<<"Scegli unita':\n 1) Arciere\n 2) Spadaccino\n";
	cin>> app;
	
	switch (app){
		case 1:
			pedina = new Archery;
			pedina->Attack();
			break;
		
		case 2:
			pedina = new Swordman;
			pedina->Attack();
			break;
	}
}
