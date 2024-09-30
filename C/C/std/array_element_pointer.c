#include <stdio.h>

void display(int num);

int main()
{
    int t[10], i;
    for (i = 0; i < 10; i++) t[i]=i;
    for (i = 0; i < 10; i++) display(t[i]);
    
    return 0;
}

void display(int num)
{
    printf("%i ", num);
}