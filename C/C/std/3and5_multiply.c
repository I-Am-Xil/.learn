#include<stdio.h>

int main()
{
    int i = 0;
    double SumaXY;
    while (i < 1000)
    {
        int X = i % 3;
        int Y = i % 5;
        if (X == 0 || Y == 0)
        {
            //printf("%i ", i);
            SumaXY = i + SumaXY;    
        }
        i++;
    }
    //printf("\n");
    printf("El resultado de la suma de todos los multiplos de 3 y 5 es: %0.f", SumaXY);
    return 0;
}