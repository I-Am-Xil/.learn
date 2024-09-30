//TODO: encontrar el factor mas grande de 600851475143
//! Usar Algofitmo de Fermat

#include<stdio.h>
#include<math.h>

int factor(double x);

int main()
{
	double x = 600851475143;
	double y = 600851475143;

	while (y > 1)
	{
		y = y / factor(y);
	}
    return 0;
}

int factor(double x)
{
	int i = 2;
	while (i*i < x)
		{
			while (fmod(x, i) == 0 && i > 1)
			{
				x = x / i;
			}
			i++;
		}
	printf("%0.f\n", x);
	return x;
}