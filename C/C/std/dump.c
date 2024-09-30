//TODO: El output de este programa es el texto escrito en cadenas de SIZE [bits] en hexadecimal y despues en ASCII

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#define SIZE 128

char buf[SIZE];

void display(int numread);

int main(int argc, char *argv[]){
    FILE *fp;
    int sector, numread;

    //! if incorrect number of args, then error
    if (argc != 2)
    {
        printf("Usage: dump filename");
        exit(1);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }

    for(;;)
    {
        printf("Enter sector (-1 to quit): ");
        scanf("%ld", &sector);
        if(sector < 0) break;
        if (fseek(fp, sector*SIZE, SEEK_SET))
        {
            printf("Seek error\n");
        }

        if ((numread = fread(buf, 1, SIZE, fp)) != SIZE)
        {
            printf("EOF reached\n");
        }

        display(numread);
    }    

    return 0;
}

void display(int numread){
    int i, j;

    for ( i = 0; i <= numread; i++)
    {
        for(j = 0; j < 16; j++) printf("%3X", buf[i*16+j]);
        printf("    ");
        for ( j = 0; j < 16; j++)
        {
            if (isprint(buf[i*16+j]))
            {
                printf("%c", buf[i*16+j]);
            }else
            {
                printf(".");
            }
        }
        printf(".");
    }
    
}