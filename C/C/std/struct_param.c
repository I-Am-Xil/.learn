#include <stdio.h>

struct sample {
    int a, b;
    char ch;
};

void f1(struct sample parm);

int main(){

    struct sample arg;

    arg.a = 1000;

    f1(arg);
    return 0;
}

void f1(struct sample parm){
    printf("%d", parm.a);
}