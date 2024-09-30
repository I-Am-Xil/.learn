#include <stdio.h>
#include <curses.h>

int main()
{
	int num1,num2,resultado;
	int a=12;
	int b=3;

	printf("Ingrese el primer valor\n");
	scanf("%d",&num1);
	printf("Ingrese el segundo valor\n");
	scanf("%d",&num2);

	resultado = a*(num1 + num2)+ b*(b+num2);

	printf("El resultado de la suma es:%d\n",resultado);
	
	return 0;
}