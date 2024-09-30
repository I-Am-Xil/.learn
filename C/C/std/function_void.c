#include <stdio.h>

void print_vertical(char *str);

int main()
{
    print_vertical("hello");
    return 0;
}

void print_vertical(char *str)
{
    while (*str)
    {
        printf("%c\n", *str++);
    }
    
}