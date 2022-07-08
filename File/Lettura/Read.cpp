#include <iostream>

using namespace std;

int main()
{
	FILE *fp;
	char path [128], content;
	
	cout << "Inserire percorso file --> ";
	cin >> path;
	
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
	
	return 0;
}
