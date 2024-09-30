#include <stdio.h>
#include <string.h>

char *p =  "hola mundo";

int main()
{
    /**
     * TODO: "register" sugiere al preprocesador que variables guardar en el cpu y no en memoria RAM (Desutilizada pero aun valida en C++)*/
    register int t;

    /*imprime la cadena fordward y backwards*/
    printf("%s\n", p);
    for (t = strlen(p)-1; t > -1; t--)
    {
        printf("%c", p[t]);
    }
    
    return 0;
}