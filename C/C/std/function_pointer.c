#include<stdio.h>
#include<string.h>

void check(char *a, char *b, int (*cmp)());

int main(){

    char s1[80], s2[80];
    int (*p)();

    p = strcmp; //TODO: Assign pointer to function

    printf("Enter the first string: ");
    gets(s1);
    printf("Enter the second string: ");
    gets(s2);

    check(s1, s2, p);
    return 0;
}

void check(char *a, char *b, int (*cmp)()){
    printf("Testing for equality\n");
    if (!(*cmp)(a, b))
    {
        printf("Equal");
    }else
    {
        printf("Not equal");
    }
    
    
}