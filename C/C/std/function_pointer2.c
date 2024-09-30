#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void check(char *a, char *b, int (*cmp)());
int numcmp(char *a, char *b);

int main(){
    char s1[80], s2[80];

    gets(s1);
    gets(s2);

    if (tolower(*s1) <= 'z' && tolower(*s1) >= 'a')
    {
        check(s1, s2, strcmp);
    }else
    {
        check(s1, s2, numcmp);
    }

    return 0;
}

void check(char *a, char *b, int (*cmp)()){
    
    printf("Testing for equatily\n");
    if (!(*cmp)(a,b))
    {
        printf("Equal");
    }else
    {
        printf("Not equal");
    }

}

int numcmp(char *a, char *b){
    if (atoi(a)==atoi(b))
    {
        return 0;
    }else
    {
        return 1;
    }
    
}