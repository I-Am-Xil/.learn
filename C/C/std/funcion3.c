/*
	Funciones de retorno en C
*/
#include <stdio.h>	/*Discursiva include*/
int suma();
/*podemos utilizar esta variable global en cualquier función*/
int num3= 2;
/*funcion main inicia la ejecucion del programa*/
int main()
{
	int num1,num2;
	printf("ingresa el primer valor\n");
	scanf("%i",&num1);
	printf("ingresa el segundo valor\n");
	scanf("%i",&num2);
	printf("El resultado es: %i\n",suma(num1,num2));
	return 0;	/*indica que el programa terminó con exito*/
}/*fin de la función main*/
int suma(int num1, int num2)
{
	int suma = num1 + num2 + num3;
	return suma;
}
