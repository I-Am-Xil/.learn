#include<stdio.h>

int series(void);

int main(){
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d ", series());
    }
    
    return 0;
}

int series(){

    static int series_sum;

    series_sum=series_sum+23;

    return series_sum;
}