/*
	Estructuras en C
*/
#include <stdio.h>
struct perro
{
	char nombre[30];
	int edadmeses;
	float peso;
}perro1={"gato",10,3.50},
perro2={"roberto",4,2.30};

int main()
{
	printf("El peso de %s es %.2f kg y tiene %d meses \n",perro2.nombre,perro2.peso,perro2.edadmeses);
	return 0;
}