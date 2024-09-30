/*
	Funciones basicas en C
*/
#include <stdio.h>	/*Discursiva include*/
int suma();
/*funcion main inicia la ejecucion del programa*/
int main()
{
	printf("%i\n",suma());
	return 0;	/*indica que el programa terminó con exito*/
}/*fin de la función main*/
int suma()
{
	int num1 =12;
	int num2 =4;
	int suma = num1 + num2;
	return suma;
}
