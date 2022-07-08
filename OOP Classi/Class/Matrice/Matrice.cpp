#include<iostream>

using namespace std;

class matrice2d{

		public: 
		
			//ctor
	
			matrice2d(double v[2][2]);
	
			//defctor
			
			matrice2d();
	
			//copyctor
			
			matrice2d(const matrice2d& original);
			
			//metodi
			void operator=(const matrice2d& original);
			matrice2d operator+(const matrice2d& original);	
			matrice2d operator*(const matrice2d& original);	
			matrice2d operator*(const double& k);
			
			double trace();
			
			void printDiag();
			void stampa();


		private:

			double v_p[2][2];
		


};

matrice2d::matrice2d(double v[2][2]){

		for(int i = 0; i < 2; i++ ){

			for(int j = 0; j < 2; j++ ){
			
				v_p[i][j] = v[i][j];

			}

		}

}

matrice2d::matrice2d (){

		for(int i = 0; i < 2; i++ ){

			for(int j = 0; j < 2; j++ ){
			
				if( i == j )
					v_p[i][j] = 1.;
				else
					v_p[i][j] = 0.;

			}

		}


}

matrice2d::matrice2d (const matrice2d& original){

	for(int i = 0; i < 2; i++){

			for(int j = 0; j < 2; j++){
	
				v_p[i][j] = original.v_p[i][j];

			}

	}
}

void matrice2d::operator=(const matrice2d& original){

	for(int i = 0; i < 2; i++){

			for(int j = 0; j < 2; j++){
	
				v_p[i][j] = original.v_p[i][j];

			}

	}
}

matrice2d matrice2d::operator+(const matrice2d& original){
	
	double v_somma[2][2];
	
	for(int i = 0; i < 2 ; i++){
		for(int j = 0; j < 2; j++ ){
			v_somma[i][j] = v_p[i][j] + original.v_p[i][j];
		}
	}
	
	matrice2d matrice_somma(v_somma);
	
	return matrice_somma;

}

matrice2d matrice2d::operator*(const double& k){

	
	double v_prodotto[2][2];
		
		for(int i = 0; i < 2 ; i++){
		
			for(int j = 0; j < 2; j++ ){
		
				v_prodotto[i][j] = k*v_p[i][j];

			}

		}
		
	matrice2d matrice_prod(v_prodotto);
	
	return matrice_prod;


}

matrice2d matrice2d::operator*(const matrice2d& original){

	
	double v_prodotto[2][2];
	
	for(int i = 0; i < 2 ; i++){
		
			for(int j = 0; j < 2; j++ ){
		
				v_prodotto[i][j] = 0.;

			}

		}
		
		for(int i = 0; i < 2 ; i++){
		
			for(int j = 0; j < 2; j++ ){

				for(int k = 0; k < 2; k++)
		
				v_prodotto[i][j] = v_prodotto[i][j] + v_p[i][k]*original.v_p[k][j];

			}

		}
		
	matrice2d matrice_prod(v_prodotto);
	
	return matrice_prod;


}

double matrice2d::trace(){
	double somma = v_p [0] [0] + v_p [1] [1];
	
	return somma;
}

void matrice2d::printDiag(){
	cout << v_p [0] [0];
	cout << "\n\t" << v_p [1] [1];
}

void matrice2d::stampa(){

		for(int i = 0; i < 2 ; i++){
		
			for(int j = 0; j < 2; j++ ){
		
				cout << v_p[i][j] << "\t";

			}

			cout << "\n";
		}
		
}

int main()
{
	double v [2] [2] = {0, 1, 2, 2};
	
	matrice2d A (v);
	matrice2d B;
	matrice2d C(A);
	
	matrice2d sum = A+B;
	matrice2d prod = A*A;
	matrice2d prodB = A*B;
	
	//Richiamo Stampe
	
	cout << "Stampa Matrice\n";
		
	A.stampa();
	cout << "\n";
	
	B.stampa();
	cout << "\n";
	
	C.stampa();
	cout << "\n";
	
	cout << "Stampa Somma\n";
	
	sum.stampa();
	cout << "\n";
	
	cout << "Stampa Prodotto\n";
	
	prod.stampa();
	cout << "\n";
	
	prodB.stampa();
	cout << "\n";
	
	cout << "Stampa Diagonale\n";
	
	A.printDiag();
	cout << "\nSomma --> " << A.trace();
	cout << "\n---------------------\n";
	
	B.printDiag();
	cout << "\nSomma --> " << B.trace();
	cout << "\n---------------------\n";
	
	prodB.printDiag();
	cout << "\nSomma --> " << prodB.trace();
	cout << "\n---------------------\n";
	
	prod.printDiag();
	cout << "\nSomma --> " << prod.trace();
	cout << "\n";
}
