/*Ejemplo simple de string*/

#include <stdio.h>

int main()
{
	char str[10];
	printf("Ingrese una cadena\n");
	gets(str);

	printf("Ingresaste: %s\n",str);
	return 0;
}