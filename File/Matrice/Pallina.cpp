#include <iostream>

using namespace std;

#define R 10
#define C 10

int main()
{
	FILE *fp;
	char path [FILENAME_MAX];
	float mat [R] [C];
	int i, j;
	
	cout << "Inserire percorso file --> ";
	cin >> path;
	
	fp = fopen (path, "r");
	
	if (fp == NULL){
		cout << "Errore di lettura!!";
		
		exit (1);
	}

   	for (i=0; i<R; i++)
      	for (j=0; j<C; j++)
         	fscanf(fp, "%f", &mat[i][j]);
         	
    int r=1, c=1;
    float val;
	
	while (true){
    	//mat [0] [0]
    	val = mat [r] [c];
    	cout << "Posizione (" << r << ", " << c << ") --> " << val << endl;
    	if (mat [r+1] [c] < val){
    		r=r+1;
    		val = mat [r] [c];
		}
		
		else if (mat [r] [c+1] < val){
    		c=c+1;
    		val = mat [r] [c];
		}
		
		else if (mat [r+1] [c+1] < val){
    		c=c+1;
    		r=r+1;
    		val = mat [r] [c];
		}
		
		else if (mat [r-1] [c] < val){
    		r=r-1;
    		val = mat [r] [c];
		}
		
		else if (mat [r] [c-1] < val){
    		c=c-1;
    		val = mat [r] [c];
		}
		
		else if (mat [r-1] [c-1] < val){
    		c=c-1;
    		r=r-1;
    		val = mat [r] [c];
		}
		
		else
			exit (10);
			
		cout << "Posizione (" << r << ", " << c << ") --> " << val << endl;
	}
   	
	fclose(fp);
	
	return 0;
}
