#include<stdio.h>
#include<string.h>
int main()
{
    char str[80];

    gets(str);
    printf("Length is %d", strlen(str));
    
    return 0;
}