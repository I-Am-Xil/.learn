#include <stdio.h>

/*display the string left after the first space in encountered*/

int main()
{
	char s[80];
	char *p;
	int i;

	printf("Enter a string: ");
	gets(s);

	/*find first space or end of string*/
	for (i = 0; s[i] != ' '; ++i);

		p = &s[i];	

		printf(p);
		
	return 0;
}