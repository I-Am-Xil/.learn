#include <stdio.h>
#include <conio.h>

char *match(char c, char *s);

int main()
{
    char a[80], *p, ch;

    printf("enter a string and a character: ");
    gets(a);
    ch = getche();
    printf("\n");
    p = match(ch, a);

    if (p)
    {
        printf("%s", p);
    }else{
        printf("no match found");
    }
    
    return 0;
}

char *match(char c, char *s) //* El nombre de un arreglo sin indice es un puntero al primer elementeo del arreglo
{
    int i = 0;
    
    /*Look for match or null terminator*/
    while (c != s[i] &&  s[i] != '\0')
    {
        i++;
    }

    if (s[i])
    {
        return (&s[i]);
    }else{
        return (char *) '\0';
    }
    
    
}