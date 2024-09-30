#include <stdio.h>

void serror();

char *err[] = {
    "cannot open fill\n",
    "read error\n",
    "write error\n",
    "media failure\n"
};

int main()
{
    int i;
    int *p = &i;

    printf("Ingrese un numero\n");
    scanf("%d", &i);
    
    if (*p < 4 && *p > -1)
    {
        serror(p);    
    }else{
        printf("Error 404: Error not found");
    }
    
    return 0;
}

void serror(int *num)
{
    printf("%s", err[*num-1]);
}