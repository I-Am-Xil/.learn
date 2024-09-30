#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    float sample[100];
    int i;

    if ((fp=fopen("sample", "wb")) == NULL)
    {
        printf("Cannot open the file\n");
        exit(1);
    }

    for(i = 0; i< 100; i++) sample[i] = (float) i;

    //*Este arreglo guarda todo el arreglo en un paso
    if (fwrite(sample, sizeof(sample), 1, fp) != 1)
    {
        printf("File Error");
    }

    fclose(fp);
    
    return 0;
}