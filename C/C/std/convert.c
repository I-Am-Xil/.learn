/*
	palabras reservadas y conversion de tipos de datos (casting)
*/
#include <stdio.h>
int main()
{
	int a = 80;
	float f = 45.3;
	float suma = (float)a + f;
	/*printf("entero %i\n flotante %.2f\n double %.3f\n caracter %c\n",a, (float)a, (double)a, (char)a);*/
	printf("%.2f\n",suma);
	return 0; /*termina el programa*/
}