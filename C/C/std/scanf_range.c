#include<stdio.h>

int main()
{
    char str[80];

    printf("Enter digits and letters: ");
    //scanf("%78[^a-z0-9]", str); //*Scanset invertido
    scanf("%78[a-z0-9]", str);    //*Scanset
    printf("\n%s", str);
    return 0;
}