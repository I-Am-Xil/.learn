#include<stdio.h>
#include<stdlib.h>

int main(){

    int *p, t;
    p = malloc(40*sizeof(int));
    if (!p) //! asegurarse es un puntero valido
    {
        printf("Error al asignar memoria");
    }else{
        for ( t = 0; t < 40; t++) *(p+t) = t;
        for ( t = 0; t < 40; t++) printf("%d ", *(p+t));
        free(p);
    }

    return 0;
}