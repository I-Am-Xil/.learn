
//! La respuesta es 142913828922

#include<stdio.h>
#include<math.h>

double identificador(long n);

int main()
{
    long dividendo = 1;
    double suma = 0;
    double id;
    while (dividendo <= 2000000)
    {
        id = identificador(dividendo);
        if (id != 0)
        {
            suma = suma + id;
            printf("%0.f\n", suma);
        }
        dividendo++;
    }
    
    return 0;
}

double identificador(long n)
{
    double i = 1;
    int divisores = 0;

    while (i <= n && n > 1 && divisores != 3)
    {
        if (fmod(n,i) == 0)
        {
            divisores++;
        }
        i++;
    }

    if (divisores == 2)
    {
        return n;
    }
    
    return 0;
}