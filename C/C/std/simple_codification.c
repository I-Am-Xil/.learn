//! Some letters dont work

#include<stdio.h>
#include<conio.h>

int main(){

    char ch;

    do
    {
        ch = getch();
        printf("%c", ~ch);
    } while (ch != 'q');

    return 0;
}