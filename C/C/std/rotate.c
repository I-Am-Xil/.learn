//* Do a rotation

#include<stdio.h>

union rotate
{
    char ch[2];
    unsigned int i;
}rot;


void display_binary(int i);
void rotate_it(union rotate *rot);


int main(){
    rot.ch[0] = 101;

    for (int t = 0; t < 7; t++)
    {
        display_binary(rot.i);
        rotate_it(&rot);
    }
    return 0;
}


void rotate_it(union rotate *rot){
    rot->ch[1] = 0;         //* Clear the high order byte
    rot->i = rot->i << 1;   //* Shift once to the left

    //* See if a bit has been shifted out of ch[0]
    if(rot->ch[1]) rot->i = rot->i | 1;
}


void display_binary(int i){
    for (int t = 128; t > 0; t = t/2)
        if(i & t) printf("1 ");
        else printf("0 ");
    printf("\n");
    
}