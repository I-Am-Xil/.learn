//TODO: Este programa suena una sirena

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

void siren(int freq);

int main()
{
    siren(1000);
    return 0;
}

void siren(int freq)
{
    while (freq > 100)
    {
        //*Beep(frequencia, tiempo);
        Beep(freq,100);
        freq = freq - 100;
    }

}