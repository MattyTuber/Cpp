#include <stdlib.h>
#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
	FILE *fp;	

	int cnt = 0;
	char path [128], content;
	
	cout << "Inerire percorso file --> ";
	cin >> path;
	getchar();
	
	fp = fopen(path, "r");
	
	if (fp == NULL){
		cout << "Errore di lettura!!";
		
		return (1);
	}
	
	content = fgetc (fp);
	
	while(content != EOF){
		if (isdigit(content))	
			cnt++;
			
		content = fgetc (fp);
	}
	
	fclose (fp);
	
	cout << "Contatore --> " << cnt;
	
	return 0;
}
