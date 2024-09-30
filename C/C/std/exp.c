/*
 Generador de exponentes n^n
*/
#include <stdio.h>
float n;
int main()
{
	printf("Ingrese el valor de n\n");
	scanf("%f",&n);
	float res = n;
	if (n == 0)
	{
		printf("El resultado es: 1\n");
	}else{
		
		
		for (int i = 1; i < n; ++i)
		{
			res = res * n;
		}

		printf("El resultado es: %f\n",res);
	}
	return 0;
}