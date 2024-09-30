#include<stdio.h>
#include<conio.h>
#include<ctype.h>

int main()
{
    char ch;

    printf("Enter chars, enter a period to stop\n");
    do
    {
        ch = getche();
        if (islower(ch))
        {
            putchar(toupper(ch));
        }else
        {
            putchar(tolower(ch));
        }
        
        
    } while (ch != '.'); //* use a period to stop
    
    return 0;
}