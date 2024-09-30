#include <stdio.h>
#include <stdlib.h>

/**
 * * Cuenta el numero de parametros de linea de comandos: argc
 * * Cuenta el numero de cadenas separadas por espacios o tabs: *argv
 */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("You forgot to type your name\n");

        //*exit() termina todo el programa
        exit(0);
    }
    printf("Hola ");

    /**
     * *Este ciclo se puede evitar poniendo el parametro de linea de comando entre comillas (en consola)*/
    for(int i = 1; i < argc; i++)
        printf("%s ",argv[i]);
    
    return 0;
}