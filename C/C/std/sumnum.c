/*
	Suma de los n primeros números
*/
#include <stdio.h>

int n,res;
int main()
{
	printf("Ingrese el valor de el ultimo numero en la serie\n");
	scanf("%i",&n);
	res = n*(n+1)/2;
	printf("El resultado es: %i\n",res);
	return 0;
}