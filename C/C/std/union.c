#include <stdio.h>
#include <conio.h>

//* A bit-field that will be decoded
struct byte{
    //* Nombre de cada bit en el byte
    int a : 1;
    int b : 1;
    int c : 1;
    int d : 1;
    int e : 1;
    int f : 1;
    int g : 1;
    int h : 1;
};

union bits
{
    char ch;
    struct byte bit;
} ascii;

void decode(union bits b);


int main(){
    do
    {
        ascii.ch = getche();
        printf(": ");
        //* Pase de la union donde está codificado el caracter
        decode(ascii);
    } while (ascii.ch!='q'); //* Quit if q typed
    
    return 0;
}

//* Display the bit pattern for each character
void decode(union bits b){
    //* Si este bit está ocupado, entonces imprime 1
    if(b.bit.h) printf("1 ");
        else printf("0 ");
    if(b.bit.g) printf("1 ");
        else printf("0 ");
    if(b.bit.f) printf("1 ");
        else printf("0 ");
    if(b.bit.e) printf("1 ");
        else printf("0 ");
    if(b.bit.d) printf("1 ");
        else printf("0 ");
    if(b.bit.c) printf("1 ");
        else printf("0 ");
    if(b.bit.b) printf("1 ");
        else printf("0 ");
    if(b.bit.a) printf("1 ");
        else printf("0 ");
    printf("\n");
}