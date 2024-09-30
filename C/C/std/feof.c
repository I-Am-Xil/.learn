//TODO: copia un archivo

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *in, *out;
    char ch;

    if (argc != 3)
    {
        printf("You forgot to enter a filename\n");
        exit(1);
    }

    if ((in = fopen(argv[1], "rb")) == NULL)
    {
        printf("Cannot open sourse file\n");
        exit(1);
    }

    if ((out =  fopen(argv[2], "wb")) ==  NULL)
    {
        printf("Cannot open destination file");
        exit(1);
    }
    
    //* This code actually copies the file
    while (!feof(in))
    {
        ch = getc(in);
        if (ferror(in))
        {
            printf("Error reading the file");
            break;
        }
        putc(ch, out);
        if (ferror(out))
        {
            printf("Error writing the file");
            break;
        }
    }

    fclose(in);
    fclose(out);
    
    return 0;
}