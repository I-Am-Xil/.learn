#include<stdio.h>


double suma_cuadrados();
double cuadrado_suma();

int main()
{
    printf("%0.f\n", suma_cuadrados());
    printf("%0.f\n", cuadrado_suma());
    printf("%0.f\n", cuadrado_suma()-suma_cuadrados());
    return 0;
}

double suma_cuadrados()
{
    int i = 1;
    double suma = 0;

    while (i <= 100)
    {
        suma = i*i + suma;
        i++;
    }
    
    return suma;
}

double cuadrado_suma()
{
    double suma = 0;
    int i = 1;

    while (i <= 100)
    {
        suma = i + suma;
        i++;
    }
    suma = suma*suma;
    
    return suma;
}
