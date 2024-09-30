/*
	Ejercicio serie fibonacci
*/
/*
0 1 1 2 3 5 8 13... (x_n-1) + (x_n)
*/
/*
	gcc fibonacci.c -o fibonacci.exe
*/
#include <stdio.h>

int n,x = 0,y = 1, z = 1;
int main()
{
	printf("ingrese el n-esimo numero que desea imprimir de la serie de fibonachi\n");
	scanf("%i",&n);

	printf("1");
	for (int i = 0; i < n; ++i)
	{
		z = y + x;
		x = y;
		y = z;
		printf(" - %i",z);
	}
	return 0;
}