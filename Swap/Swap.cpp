#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2){
	int temp;
	
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main()
{
	int num1, num2;
	
	printf ("Inserire Primo Numero --> ");
	scanf ("%d", &num1);
	
	printf ("Inserire Secondo Numero --> ");
	scanf ("%d", &num2);
	
	swap (&num1, &num2);
	
	printf ("\nPrimo Numero --> %d", num1);
	printf ("\nSecondo Numero --> %d", num2);
}
