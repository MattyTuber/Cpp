#include <iostream>

using namespace std;

struct elenco{
	string nome;
	
	int eta;
};

int main()
{
	int N, i, ricerca;
	
	cout << "Inserire il numero di persone --> ";
	cin >> N;
	
	struct elenco id [N];
		
	for (i=0; i<N; i++){
		cout << "Inserire Nome --> ";
		cin >> id[i].nome;
		
		cout << "Inserire Eta' --> ";
		cin >> id[i].eta;
	}
	
	cout << "Eta' da ricercare --> ";
	cin >> ricerca;
	
	for (i=0; i<N; i++){
		if (id[i].eta == ricerca)
			cout << id[i].nome << endl;
	}
	
	return 0;
}
