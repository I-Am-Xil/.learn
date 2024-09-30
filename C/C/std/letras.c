/*
	Imprimir las letras del alfabeto
*/
#include <stdio.h>

int main()
{
	char i = 'a';
	do{
		printf("%c ",i);
		i++;
	}while(i <= 'z');

	return 0;
}