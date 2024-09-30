#include <stdio.h>

void swap (); 

int main()
{
    int x = 10, y = 20;

    printf("valores iniciales de (x,y): %d,%d\n", x, y);
    swap(&x,&y);
    printf("valores cambiados de (x,y): %d,%d", x, y);
    return 0;
}

void swap (int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}