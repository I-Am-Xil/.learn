

#include <stdio.h>

void sqr(int x)
{
	printf("%d el cuadrado es %d\n",x,x*x);
}

int main()
{
	int num;
	num = 100;
	sqr(num);
	return 0;
}