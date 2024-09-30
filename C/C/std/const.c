#include<stdio.h>

void code(const char *str);

int main(){

    code("this is a test");
    return 0;
}

void code(const char *str){
    while (*str)
    {
        printf("%c", (*str++)+1);
    }
    
}