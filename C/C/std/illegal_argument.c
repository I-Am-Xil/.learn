#include <stdio.h>

//! Dont use this program, its an example of illegal arguments in C/C++

void sqr_it(int *i);

int main()
{
    int x = 10;

    sqr_it(x); //! Type mismatch 

    return 0;
}

void sqr_it(int *i)
{
    *i = *i * *i;
}