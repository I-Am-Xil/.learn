/*
	Encontrar los n primeros números primos
*/

#include <stdio.h>

int main()
{
	int n,i,cont = 0;
	printf("Ingrese el ultimo número que desea revisar\n");
	scanf("%i",&n);
	if (n > 1)
	{
		int j = 2;
		do{
			for (i = 2; i <= j; ++i)
			{
				if (j%i==0)
				{
					cont++;
				}
			}

			if (cont < 2)
			{
				printf("El número %i es primo\n",j);
			}
			cont = 0;
			j++;
		}while(j <= n);
	}else{
		printf("No existen números primos en este rango\n");
	}

	return 0;
}