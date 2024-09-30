/*
	suma de los numeros par desde 1 hasta n
*/

#include <stdio.h>
int n,i,suma;
int main()
{
	printf("Ingrese el ultimo número que desea sumar\n");
	scanf("%i",&n);
	i = 1;
	while(i <= n){
		if (i%2==0)
		{
			suma += i;
		}
		i++;
	}
	printf("El resultado de la suma es: %i\n",suma);
	return 0;
} 