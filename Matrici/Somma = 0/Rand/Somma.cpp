#include <iostream>
#include <cstdlib>
#include <ctime>

#define NR 10
#define NC 10

using namespace std;

int main(int argc, char const *argv[])
{
	int mat [NR] [NC], i, j, n, m, R, C, somma = 0, r, random;

	srand(time(NULL));

	for (i = 0; i < NR; ++i)
	{
		for (j = 0; j < NC; ++j)
		{	
			r = rand()%200;
			
			random = r - 100;

			mat [i] [j] = random;
         	cout << mat [i] [j] << "\t";
		}

		cout << endl;
	}

	cout << "Inerire il numero di righe --> ";
	cin >> R;

	cout << "Inserire il numero di colonne --> ",
	cin >> C;

	for (i=0; i<=NR-R+1; ++i)
   	{
    	for (j=0; j<=NC-C+1; ++j)
      	{
	      	somma = 0;

	        for (n=0; n<R; ++n)
	        {
	        	for (m=0; m<C; ++m)
	            {
	            	somma += mat [i+n] [j+m];
	            }
	        }
		    if (somma == 0)
		    {
		        for (n = 0; n < R; ++n)
		        {
		            for (m = 0; m < C; ++m)
		            {
		            	cout << mat [i+n] [j+m] << "\t";
		            }

		            cout << "\n\n\n";
		        }   
	   		}
		}
	}

	return 0;
}
