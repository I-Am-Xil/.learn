/*
	Directivas del procesador
*/
#include <stdio.h>
/*#include "nombre del archivo"*/
#define CUBO(a) a*a*a
#define PI 3.14159
int main()
{
	/*int suma;
	suma = PI +3;*/
	int a = 3;
	printf("El cubo de la variable a es :%i\n",CUBO(a));
	return 0;
}