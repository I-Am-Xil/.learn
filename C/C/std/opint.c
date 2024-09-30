/*
	Expresión condicional: el operador '?'
Sintaxix:

condicion ? Expresión1 : Expresión2;
*/

#include <stdio.h>

int main()
{
	int numero;

	printf("Digite un número\n");
	scanf("%i",&numero);

	(numero%2==0) ? printf("El número es par\n") : printf("El número es impar\n");
	

	return 0;
}