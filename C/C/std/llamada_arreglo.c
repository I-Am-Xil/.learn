#include <stdio.h>

void display(int num[]);
void display2(int *num);
void display3(int num[10]);

int main()
{
    int t[10];

    for (int i = 0; i < 10; i++)
    {
        t[i] = i;
    }

    display(t);
    printf("\n");
    display2(t);
    printf("\n");
    display3(t);
    
    return 0;
}

//* Forma con arreglo como parametro
void display(int num[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
    
}

//* Forma con puntero como parametro
void display2(int *num)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
    
}

void display3(int num[10])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
    
}