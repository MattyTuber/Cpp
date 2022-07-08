#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	FILE *fp;
	char path [128], content;
	
	cout << "Inserire percorso file --> ";
	cin >> path;
	getchar();
	
	fp = fopen (path, "r");
	
	if (fp == NULL){
		cout << "Errore nella lettura!!";
		return (1);
	}
	
	content = fgetc (fp);
	
	while (!feof(fp)){
		cout << content;
		content = fgetc (fp);		
	}
	
	fclose(fp);
	
	char item [255], end;
	
	fp = fopen (path, "a");
	
	while (true){
		cout << "\nInserire Articolo --> ";
		gets (item);
		fprintf(fp, "\n%s", item);
		
		cout << "K per terminare --> ";
		cin >> end;
		getchar();
		
		if (end == 'K')
			return 0;
	}
	
	if (fp == NULL){
		cout << "Errore nella scrittura!!";
		return (1);
	}
	
	fclose (fp);
	
	return 0;
}
