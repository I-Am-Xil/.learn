#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    float sample[100];
    int i;

    if ((fp = fopen("sample", "rb")) == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }
    
    if (fread(sample, sizeof(sample), 1, fp) != 1)
    {
        printf("File Error");
    }

    for(i = 0; i < 100; i++) printf("%.0f ", sample[i]);

    fclose(fp);

    return 0;
}