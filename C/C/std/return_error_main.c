#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (system(argv[i]))
        {
            printf("%s failed", argv[i]);
            return -1;
        }
    }
    
    return 0;
}