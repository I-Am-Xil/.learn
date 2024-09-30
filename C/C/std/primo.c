/*
	Determinar si un número es primo
*/

#include <stdio.h>

int main()
{
	int n,i,cont = 0;

	printf("Ingrese un número\n");
	scanf("%i",&n);
	
	for (i = 1; i <= n; ++i)
	{
		if (n%i==0)
		{
			cont++;
		}
	}

	if (cont > 2)
	{
		printf("El numero no es primo\n");
	}else{
		printf("El numero es primo\n");
	}
	return 0;
}