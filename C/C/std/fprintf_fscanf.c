//TODO: este programa tiene un bug al añadir y despues leer un directorio

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void add_num(void), lookup(void);
int menu(void);

int main(){ //*fscanf - fprintf example
    char choice;

    while (choice != 'q')
    {
        choice = menu();
        switch(choice){
            case 'a':
                add_num();
                break;
            case 'l':
                lookup();
                break;
        }
    }
    
    return 0;
}

//*Display menu and get request
int menu(){
    char ch;

    while (ch != 'q' && ch != 'a' && ch != 'l')
    {
        printf("(A)dd, (L)ookup or (Q)uit: ");
        ch = tolower(getche());
        printf("\n");
    }
    
    return ch;
}

//*Add a name and number to the directory
void add_num(){
    FILE *fp;
    char name[80];
    int a_code, exchg, num;

    //*Open it for append
    if ((fp = fopen("phone", "a")) == NULL)
    {
        printf("Cannot open directory");
        exit(1);
    }

    printf("Example Logan 81 1171 5804\n");
    printf("Enter name and number: ");
    fscanf(stdin, "%s%d%d%d", name, &a_code, &exchg, &num);

    //*Write to file
    fprintf(fp, "%s %d %d %d\n", name, a_code, exchg, num);
    
    fclose(fp);
}

void lookup(){
    FILE *fp;
    char name[80], name2[80];
    int a_code, exchg, num;

    //*Open it for read
    if ((fp = fopen("phone", "r")) == NULL)
    {
        printf("Cannot open directory");
        exit(1);
    }

    printf("name? ");
    gets(name);
    
    //*look for number
    while (!feof(fp))
    {
        fscanf(fp, "%s%d%d%d", name2, &a_code, &exchg, &num);
        if (!strcmp(name, name2))
        {
            printf("%s: (%d) %d-%d\n", name, a_code, exchg, num);
            break;
        }
    }
    fclose(fp);
}
