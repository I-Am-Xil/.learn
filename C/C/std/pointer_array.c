#include <stdio.h>
#include <ctype.h>

/*Funcion basada en arreglos*/
void array()
{
	char strA[30];

	printf("enter a string in uppercasse\n");
	gets(strA);

	printf("here's the string in lowercase: ");

	for (int i = 0; strA[i] ; ++i)
	{
		printf("%c",tolower(strA[i]));
	}
	printf("\n");
}

/*Funcion basada en aritmetica de punteros*/
void pointer()
{
	char strP[30], *p;

	p = strP;


	printf("enter a string in uppercasse\n");
	gets(strP);

	printf("here's the string in lowercase: ");

	/*Esto es mas rapido que su analogo en array()*/
	while(*p){
		printf("%c",tolower(*p++));
	}
	printf("\n");
}

int main()
{
	array();
	pointer();
	return 0;
}