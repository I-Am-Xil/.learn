/*
	Calculadora basica de 2 numeros max
*/
#include <stdio.h>

int main()
{
	float num1,num2,resSuma,resResta,resMult,resDiv;
	int casos;
	printf("Ingrese el número correspondiente a la operacion que desea realizar\n");
	printf("Suma: 1\n");
	printf("Resta: 2\n");
	printf("Divición: 3\n");
	printf("Mutiplicación: 4\n");
	scanf("%i",&casos);
	printf("Ingrese el valor del primer número\n");
	scanf("%f",&num1);
	printf("Ingrese el valor del segundo número\n");
	scanf("%f",&num2);
	resSuma = num1 + num2;
	resResta = num1 - num2;
	resDiv = num1 / num2;
	resMult = num1 * num2;
	switch(casos)
	{
		case 1:
		printf("El resultado de la suma es: %.2f\n",resSuma);
		break;

		case 2:
		printf("El resultado de la resta es: %.2f\n",resResta);
		break;

		case 3:
		printf("El resultado de la divición es: %.2f\n",resDiv);
		break;
		
		case 4:
		printf("El resultado de la mutiplicación es: %.2f\n",resMult);
		break;
	}
	return 0;
}