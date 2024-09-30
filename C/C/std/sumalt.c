/*
	suma alternada de numeros desde 1 hasta n
*/

#include <stdio.h>

int n,i,num,suma;
int main()
{
	printf("Ingrese el ultimo numero de la suma alternada\n");
	scanf("%i",&n);
	i = 1;
	suma = 0;
	while(i <= n){
		if (i%2==0)
		{
			num = -i;
		}else{
			num = i;
		}
		suma = suma + num;
		i++;
	}
	printf("El resultado de la suma es: %i\n",suma);
	return 0;
}