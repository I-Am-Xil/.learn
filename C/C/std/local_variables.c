#include <stdio.h>

void f1();
void f2();

int main()
{
    int x = 7;

    printf("%i\n", x);
    f1();
    f2();
    printf("%i\n", x);
    return 0;
}

void f1()
{
    int x = 10; 
    printf("%i\n",x );
}

void f2()
{
    int x = -199;
    printf("%i\n",x );
}