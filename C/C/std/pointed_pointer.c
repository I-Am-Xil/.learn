/**
 * TODO: Ejemplo de un puntero a un puntero
*/

#include <stdio.h>

int main()
{
    int x, *p, **q;

    x = 10;
    p = &x;
    q = &p;

    printf("%d", **q); /* imprime el valor de x */
    return 0;
}