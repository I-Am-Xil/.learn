#include<stdio.h>

int f1(int n);
int f2(void);

int main(){

    int t;

    printf(": ");
    scanf("%d", &t);

    t ? f1(t)+f2() : printf("Zero entered");
    return 0;
}

int f1(int n){
    printf("%d ", n);
}

int f2(void){
    printf("Entered");
}