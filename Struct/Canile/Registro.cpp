#include <iostream>

using namespace std;

struct registro{
	char nome [256];
	
	char razza [256];
	
	int eta;
};

int main()
{
	int N, i, j;
	
	struct registro key;
	
	cout << "Inserire numero di Cani --> ";
	cin >> N;
	
	struct registro elenco [N];
	
	for (i=0; i<N; i++){
		getchar();
		
		cout << "Inserire Nome " << i+1 << " Cane --> ";
		gets (elenco[i].nome);
		
		cout << "Inserire Razza " << i+1 << " Cane --> ";
		gets (elenco[i].razza);
		
		cout << "Inserire Eta' " << i+1 << " Cane --> ";
		cin >> elenco[i].eta;
	}
	
	for (j = 1; j < N; ++j){
		key = elenco[j];

		for (i = j-1; i>=0 && elenco[i].eta>key.eta; i--)
			elenco[i+1] = elenco[i];
		
		elenco[i+1] = key;
	}
	
	for (i=0; i<N; i++)
	{
		cout << "\n\n";
		
		cout << "Cane " << i+1 << ":" << endl;
		
		cout << "Nome --> " << elenco[i].nome << endl;
		
		cout << "Razza --> " << elenco[i].razza << endl;
		
		cout << "Eta' --> " << elenco[i].eta;
	}
	
	return 0;
}
