/*
	Toma de decisiones
	operadores de igualdad				|	Operadores de Relacion
		==	x es igual que y					>	x es mayor que y
		!=	x es diferente que y				<	x es menor que y
												>=	x es mayor o igual que y
												<=	x es menor o igual que y
*/
#include <stdio.h>
int main()
{
	int edad;
	printf("ingresa tu edad\n");
	scanf("%d",&edad);
	if (edad >= 18)
	{
		printf("eres mayor de edad\n");
	}
	else if (edad == 17)
	{
		printf("Sorry bro, casi eres mayor de edad\n");
	}
	else{
		printf("Eres menor de edad\n");
	}
	return 0; /*termina el programa*/
}