/*
Convertidor de grados a radianes decimales
*/
#include<stdio.h>
#define PI 3.1416
float rad;
float *aptRad = &rad;
int main()
{
	for (int i = 0; i <= 90; ++i)
	{
	 	rad = i/(180 / PI);
		printf("el angulo %i en radianes es: %f\n",i,*aptRad);
	}
    return 0;
}