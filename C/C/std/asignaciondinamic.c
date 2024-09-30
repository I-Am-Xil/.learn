/*
	Asignación dinamica de memoria en C
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	char *p;

	printf("Escriba el tamaño en bytes que desea agregar a n\n");
	scanf("%i",&n);

	p = malloc(n*sizeof(char));
	
	if (NULL == p)
	{
		printf("Error al asignar memoria\n");
	}else{
		printf("Se asignó memoria\n");
	}
	return 0;
}