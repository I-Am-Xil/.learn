#include <stdio.h>

int main(){
    struct sample
    {
        int i;
        double d;
    }one, two;

    one.i = 10;
    one.d = 98.6;

    two = one; //* Assign a structure to another

    printf("%d, %3.2f", two.i, two.d);
    
    return 0;
}