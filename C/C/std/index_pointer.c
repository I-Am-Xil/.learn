#include <stdio.h>

int main()
{
	int i[5] = {1, 2, 3, 4, 5};
	int *p, t;

	p = i;

	for (t = 0; t < 5; ++t)
	{
		printf("%d\n", p[t]);
	}

	return 0;
}