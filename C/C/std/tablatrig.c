/*
    Generador de tablas trigonométricas
*/

#include<stdio.h>
#include<math.h>
#define PI 3.1416
float rad;
float *aptRad = &rad;
int main()
{
	for (int i = 0; i <= 90; ++i)
	{
		rad = i/(180 / PI);
		printf("sen %i: %f cos %i: %f tan %i: %f\n",i,sin(*aptRad),i,cos(*aptRad),i,tan(*aptRad));

	}
	return 0;
}
