#include<stdio.h>



void disp_binary(int i);

int main(){

    int i = 1;

    for (int t = 0; t < 8; t++)
    {
        disp_binary(i);
        i = i << 1;
    }

    printf("\n");

    for (int t = 0; t < 8; t++)
    {
        i = i >> 1;
        disp_binary(i);
    }
    
    return 0;
}

void disp_binary(int i){

    for (int t = 128; t > 0; t=t/2)
        if (i & t) printf("1 ");
        else printf("0 ");
    printf("\n");
    
}