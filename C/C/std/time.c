#include <stdio.h>
#include <time.h>

int main(){

    struct tm *ptr;
    time_t lt;

    lt = time('\0');

    ptr = localtime(&lt);
    printf(asctime(ptr));
    
    return 0;
}