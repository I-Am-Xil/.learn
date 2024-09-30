/*
	Definición número e
*/
#include <stdio.h>
#include <math.h>
double n;
int main()
{
	printf("Ingrese el número con el que quiere aproximar 'e'\n");
	scanf("%lf",&n);
	double res = (1 + 1 / n);
	for (int i = 1; i < n; ++i)
	{
			res = res * (1 + 1 / n);
	}
	printf("la aproximación de 'e' es: %lf\n",res); 
	return 0;
}
