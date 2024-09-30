//TODO: La diferencia entre las variables es 0 porque los compiladores modernos elijen variables para guardar en register automaticamente

#include<stdio.h>
#include<time.h>

unsigned int i;
unsigned int delay;

int main(){

    register unsigned int j;
    long t;

    t = time('\0');
    for (delay = 0; delay < 10; delay++)
    {
        for (i = 0; i < 64000; i++);
    }
    printf("time for non-register loop: %ld\n",time('\0')-t);

    t = time('\0');
    for (delay = 0; delay < 10; delay++)
    {
        for (j = 0; j < 64000; j++);
    }
    printf("time for register loop: %ld",time('\0')-t);


    return 0;
}