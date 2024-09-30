//TODO: ktod: a key to disk program

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if (argc != 2)
    {
        printf("You forgot to enter the filename\n");
        exit(1);
    }

    if ((fp = fopen(argv[1], "w")) == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    do
    {
        ch = getchar();
        
        if (EOF == putc(ch, fp))
        {
            printf("File Error");
            break;
        }

    } while (ch != '$');
    
    fclose(fp);
    
    return 0;
}