/*
	Generadora de tabla de fuerzas entre tierra y el sol durante su orbita
*/

#include <stdio.h>

int main()
{
	double fuerza,e = 1;
	
	for (int j = 0; j < 44; ++j)
	{
		e *= 10;
	}

	for (double i = 147104613000; i <= 152104613000 ; ++i)
	{
		fuerza = (7.9276778*e)/(i*i);
		printf("%.0lf\n",fuerza);
	}

	return 0;
}