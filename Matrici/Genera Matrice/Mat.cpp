#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mat (int n){
	int mat [n] [n], i, j;
	
	for (int i=0; i<n; i++){
		for (j=0; j<n; j++){
			mat [i] [j] = rand()%10;
			
			printf ("%d\t", mat [i] [j]);
		}
		printf("\n\n");
	}
}

int main()
{
	int n;
	
	srand(time(NULL));
	
	printf ("Inserire Dimenisoni Matrice --> ");
	scanf("%d", &n);
	
	mat(n);
}
