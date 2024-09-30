/*
	Calculadora basica de n números
*/
#include "stdio.h"

int main()
{
	float num1,num2;
	double res;
	double *resultado = &res;
	int casos;
	printf("Ingrese un número de la operación\n");
	scanf("%f",&num1);
	do{
		printf("Ingrese un número de la operación\n");
		scanf("%f",&num2);
		if (num2 == 0)
		{
			break;
		}
		printf("1 Suma\n");
		printf("2 Resta\n");
		printf("3 División\n");
		printf("4 Multiplicación\n");
		printf("Ingrese el número correspondiente a la operación que desea realizar\n");
		scanf("%i",&casos);
		switch(casos)
		{
			case 1:
			res = num1 + num2;
			printf("%.2lf\n", *resultado);
			num1 = res;
			break;

			case 2:
			res = num1 - num2;
			printf("%.2lf\n", *resultado);
			num1 = res;
			break;

			case 3:
			res = num1 / num2;
			printf("%.2lf\n", *resultado);
			num1 = res;
			break;

			case 4:
			res = num1 * num2;
			printf("%.2lf\n", *resultado);
			num1 = res;
			break;
		}

	}while(num2 =! 0);

	printf("El resultado es: %.2lf\n",*resultado);
	return 0;
}