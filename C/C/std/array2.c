/*
	Arreglo multidimencional en C
*/
#include <stdio.h>
/*directiva include*/
/*funcion main inicia el programa*/
int main()
{
	/*
	col		0	1	2
	fila0 	5	3	1
	fila1	6	4	2
	*/
	int multi[2][3] = {{5,3,1},{6,4,2}};
	printf("%i\n",multi[0][2]);
	return 0;	/*indica que el programa se terminó con exito*/
}	/*fin de la función main*/