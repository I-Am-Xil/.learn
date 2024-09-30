//TODOS: Este programa promedia un arbitrario numero de enteros

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p;
    int num, i, avg;

    printf("Ingrese el numero de enteros a promediar: ");
    scanf("%d", &num);

    //*Allocate space
    if ((p = malloc(sizeof(int)*num)) == NULL)
    {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    
    for ( i = 0; i < num; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", &p[i]);
    }

    avg = 0;

    for ( i = 0; i < num; i++) avg = avg + p[i];
    
    printf("El promedio es: %d", avg);
    free(p);

    return 0;
}