#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char a [256], b [256], c[256];
	int i, j, lena, lenb, app, cont = 0;

	cout << "Inserire una stringa --> ";
	gets(a);

	cout << "Inserire una stringa --> ";
	gets(b);

	lena = static_cast <int> (strlen(a));
	lenb = static_cast <int> (strlen(b));

	if (lena < lenb)
	{
		strcpy(c, a);
      	strcpy(a, b);
      	strcpy(b, c);

      	app = lena;
      	lena = lenb;
      	lenb = app;
	}

	for (i=0; i < lena-lenb+1; i++)
	{
	   	cont++;
	    for (j=0; j<lenb; j++)
	    {
	        if (a[i+j] != b[j])
	        {
	           	cont--;
	           	break;
	       	}
	    }
	}

	if (cont==1)
    	cout << "Trovata una volta";
    else
    	cout << "Trovata NON solo una volta";

	return 0;
}