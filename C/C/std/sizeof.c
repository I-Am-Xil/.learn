/*
	Operador SizeOf en C 
*/
#include <stdio.h>
size_t getsize(float *ptr);
int main()
{
	float array[20];
	printf("El número de bytes en el arreglo es: %lu\n",sizeof(array));
	printf("El número de bytes devueltos por getsize es: %lu\n",getsize(array));
	return 0;
}

size_t getsize(float *ptr)
{
	return sizeof(ptr);
}