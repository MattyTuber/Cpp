#include <iostream>

using namespace std;

struct persona{
	char cognome [20];
	char nome [20];
	
	int eta;
};

int max (struct persona *el, int num);

int main()
{
	int N, i, maxx;
	
	cout << "Inserire numero Persone --> ";
	cin >> N;
	
	struct persona elenco [N];
	
	for (i=0; i<N; i++)
	{
		getchar();
		
		cout << "Inserire Cognome --> ";
		gets (elenco[i].cognome);
	
		cout << "Inserire Nome --> ";
		gets (elenco[i].nome);
	
		cout << "Inserire Eta --> ";
		cin >> elenco[i].eta;
	}
	
	cout << "Massimo --> " << max (elenco, N);
	

	return 0;
}

int max (struct persona *el, int num)
{
	int i;
	int mass = el[0].eta;
	
	for (i=0; i<num; i++){
		if (el[i].eta > mass)
			mass = el[i].eta;
	}
	
	return mass;
}
