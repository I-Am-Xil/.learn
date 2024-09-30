#include<stdio.h>

int main()
{
    int A = 1,B = 1,C = 0;
    int suma = 0;
    while (B < 4000000)
    {
        C = A + B;
        B = A;  
        A = C;
        int X = B % 2;
        if (X == 0)
        {
            suma = suma + B;
        }
    }
    printf("%i", suma);
    return 0;
}