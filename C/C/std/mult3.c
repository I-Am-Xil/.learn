/*
	Encontrar los multipos de 3 desde 1 hasta n
*/

#include <stdio.h>

int n,i;
int main()
{
	printf("Ingrese el valor de n\n");
	scanf("%i",&n);
	i = 1;
	while(i <= n){
		if (i%3==0)
		{
			printf("Los multiplos de 3 desde 1 hasta n son: %i\n",i);
		}
		i++;
	}

	return 0;
}
