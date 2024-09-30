#include <stdio.h>
#include <string.h>

void cpy(void);
void cat(void);
void cmp(void);
void len(void);

int main()
{
	cpy();
	cat();
	cmp();
	len();
	
	return 0;
}

void cpy()
{
	char str[80];

	strcpy(str, "Hello");

	printf("%s\n", str);
}

void cat()
{
	char s1[10], s2[20];

	strcpy(s1, "Hello");
	strcpy(s2, " there");

	strcat(s1,s2);

	printf("%s\n", s1);
}

void cmp()
{
	char s[80];

	printf("Enter password: ");
	gets(s);

	if (strcmp(s, "password"))
	{
		printf("invalid password\n");
	}

}

void len()
{
	char ss[80];

	printf("Enter a string: ");
	gets(ss);

	printf("%d\n",strlen(ss) );
}