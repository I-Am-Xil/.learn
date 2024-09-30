/*
	Apuntadores en C
		"llamada a funciones por referencia"
*/
#include <stdio.h>
void cubo(int *n);
int main()
{
	int num = 5;
	printf("El valor original es: %i\n",num);
	cubo(&num);
	printf("El nuevo valor es: %i\n",num);
	return 0;
}
void cubo(int *n)
{
	*n = *n * *n * *n;
}