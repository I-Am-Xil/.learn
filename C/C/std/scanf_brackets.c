#include<stdio.h>

int main()
{
    char c;
    printf("ingrese un numero entre 0 y 9: ");
    scanf("%[a]", &c);
    printf("\n%c", c);
    return 0;
}