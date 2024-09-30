#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    FILE *fp;

    if (argc != 2)
    {
        printf("You forgot to enter the filename");
        exit(1);
    }

    if ((fp = fopen(argv[1], "w")) == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }


    for (int i = 33; i < 255; i++)
    {
        fprintf(fp, "Decimal: %3i | Hexadecimal: %2X | ASCII: %1c \n", i, i, i);
    }
    
    fclose(fp);
    return 0;
}