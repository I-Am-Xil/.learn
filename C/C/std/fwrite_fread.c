//TODO: Write a floating point number to a disk file
//TODO: El archivo resultante es literalmente un float con su direccion de memoria en el

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    float f = 11.23;

    if ((fp = fopen("test3", "wb")) == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    if (fwrite(&f, sizeof(float), 1, fp) != 1)
    {
        printf("File Error");
    }

    fclose(fp);
    return 0;
}