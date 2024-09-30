#include<stdio.h>
#include<stdlib.h>

/**
 * * Cuenta el numero de parametros de linea de comandos: argc
 * * Cuenta el numero de cadenas separadas por espacios o tabs: *argv
 */
int main(int argc, char *argv[])
{
    int i;

    for(i = 1; i < argc; i++)
        //* ejecuta el comando indicado en consola
        system(argv[i]);
    
    return 0;
}