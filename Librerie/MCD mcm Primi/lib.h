#include <algorithm>

int mcd (int num, int num2)
{
	int mcd = std::__gcd(num, num2);
	return mcd;
}
	
int mcm (int num, int num2)
{
	int t = num;
	
	while (t % num2 != 0)
		t += num;
		
	return t;
}

int primo (int num)
{
	int isPrime = 1, i;
	
	for (i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            isPrime = 0;
            	
			break;
        }
    }
    
    return isPrime;
}
