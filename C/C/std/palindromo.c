#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    char str[21];
    char *str_mirror;
    int i, j = 0;

    printf("Ingrese una cadena de hasta 20 caracteres\n");
    gets(str);

    i = strlen(str);

    if((str_mirror = malloc(i)) == NULL){
        printf("Error al asignar memoria");
        exit(1);
    }

    strcpy(str_mirror, str);

    while (i > -1){
        str_mirror[i-1] = str[j];
        i--;
        j++;
    }

    if(!strcmp(str, str_mirror)) printf("\nLa cadena ingresada es un palindromo\n");
    else printf("\nLa cadena ingresada no es un palindromo\n");
    
    printf("Cadena original: %s\n", str);
    printf("Cadena invertida: %s", str_mirror);

    return 0;
}