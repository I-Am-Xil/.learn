/*
	Arreglo unidimencional en C
*/
#include <stdio.h>
/*directiva include*/
/*funcion main inicia el programa*/
int main()
{
	int sizeA;

	printf("tamaño del arreglo\n");
	scanf("%i",&sizeA);

	int age[sizeA];

	for(int i = 0;i < sizeA;i++)
	{
		printf("ingresa el valor%i\n",i+1);
		scanf("%i", &age[i]);
	}

	printf("los valores del arreglo son:\n");

	for (int i = 0; i < sizeA;i++)
	{
		printf("%i-", age[i]);
	}

	printf("\n");
	
	return 0; /*indica que el programa se terminó con exito*/
}	/*fin de la función main*/