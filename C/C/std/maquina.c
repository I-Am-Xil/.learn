/*
	maquina de estacionamiento sin cambio
*/

#include <stdio.h>
#include <math.h>

float horas; 
int pago;
int main()
{
	printf("Ingrese las horas que ha estado estacionado su vehiculo\n");
	scanf("%f",&horas);
	int fxhoras = ceil(horas);
	unsigned int *apthoras = &fxhoras;
	printf("Esta maquina solo acepta el pago exacto\n");

	int pago = 15 + (*apthoras - 2) * 10;
	int pagado = 0;
	if (*apthoras <= 2)
	{
		pago = 15;
	}
	do{
		printf("Usted debe pagar: %i$\n",pago);
		printf("Esta maquina solo acepta monedas/billetes de 5$, 10$, 20$, 50$ y 100$\n");
		printf("Ingrese el pago\n");
		scanf("%i",&pagado);
		switch(pagado)
		{
			case 5:
			pago = pago - 5;
			break;

			case 10:
			pago = pago - 10;
			break;

			case 20:
			pago = pago - 20;
			break;

			case 50:
			pago = pago - 50;
			break;

			case 100:
			pago = pago - 100;
			break;
		}
	}while(pago > 0);
	printf("Gracias por venir, tenga un buen día.\n");
	return 0;
}