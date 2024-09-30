// TODO: Escriba  un  programa  que  lea  una  palabra  de  cinco  letras
// TODO: produzca todas  las  posibles  cadenas  de  tres  letras  que  puedan  derivarse  de  las  letras  de  la  palabra  con  cinco letras
//! Debe haber 60 salidas
//! Falta eliminar cadenas repetidas
//! Limpieza de cadenas imposibles
//* Idea: Poner en archivo binario y desde ahí eliminar las palabras iguales

#include<stdio.h>

void combinacion(char a[5]);
void limpiador(char b[5]);


int main(){
    char palabra[5];


    printf("Ingrese una palabra de 5 letras\n");
    scanf("%s", &palabra);
    printf("\n");
    //printf("%s", palabra);

    combinacion(palabra);

    return 0;
}

void combinacion(char a[5]){
    for (int j = 0, k = 0, i = 0;; i++)
    {

        if (i == 5)
        {
            i = 0;
            j++;
        }

        if (j == 5)
        {
            j = 0;
            k++;
        }
        
        if (k == 5)
        {
            return;
        }

        printf("%c%c%c\n", a[k], a[j], a[i]);
   
    }
    
}