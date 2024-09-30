/*
	Break & Continue en C
*/
#include <stdio.h>	/*directiva include*/
/*funcion main inicia la ejecucion del programa*/
int main()
{
	int num =0;
	while(num<=7)
	{
		if(num == 2)
		{
			break;
		}
		printf("%i\n",num);
		num++;
	}
	return 0;	/*indica que el programa se terminó con exito*/
}	/*Fin de la función main*/