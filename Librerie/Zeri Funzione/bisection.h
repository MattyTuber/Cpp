double x_m;

double f ( double x)
	return x * x * x - 2 * x - pow ( e , x );

double bisection(int xMin, int xMas)
{
	for (int i = 0; i < 10000 ; i ++){
		x_m = 0.5 * (xMin + xMas);
	
		if (f (xMin) * (x_m) < 0 )
			xMas = x_m;
		
		else
			xMin = x_m;
		
		return 0.5 * (xMas + xMin);
	}
}
