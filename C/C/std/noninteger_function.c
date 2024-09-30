/**
 * TODO: No es necesario el prototipo de funcion si la declaras antes de utilizarla (usualmente en main()) sinembargo se considera una buena practica
 * TODO: tambien se pueden poner en un archivo .h los prototipos (y/o las funciones)
 * TODO: En realidad no importa la mayoria de veces, entonces hazlo como tengas ganas bruh
*/

#include <stdio.h>

double sum(double a, double b); /*prototype the function*/

int main()
{
    double first, second;

    first = 1023.23;
    second = 990.9;
    
    printf("%f", sum(first,second));
    return 0;
}

double sum(double a, double b)
{
    return a+b;
}