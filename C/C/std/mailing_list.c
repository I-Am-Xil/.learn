#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<conio.h>

#define SIZE 100

struct addr
{
    char name[40];
    char street[40];
    char city[30];
    char state[3];
    char zip[10];
}addr_info[SIZE];

void enter(void), init_list(void), display(void), save(void), load(void);
int menu(void);


int main(){

    char choice;

    init_list();

    for(;;){
        choice = menu();
        switch (choice)
        {
        case 'e': 
            enter();
            break;
        
        case 'd': 
            display();
            break;
        
        case 's': 
            save();
            break;
        
        case 'l': 
            load();
            break;
        
        case 'q': 
            return 0;
        }
    }
}

//* Initialize the addr_info array
void init_list(void){
    
    for (int i = 0; i < SIZE; i++)
    {
        *addr_info[i].name = '\0';
    }

    return;
}

//* Get the menu selection
int menu(void){

    char ch;

    do
    {
        printf("(E)nter\n");
        printf("(D)isplay\n");
        printf("(L)oad\n");
        printf("(S)ave\n");
        printf("(Q)uit\n");
        printf("Choose one: ");
        ch = getche();
        printf("\n");
    } while (!strchr("edlsq", tolower(ch)));
    return tolower(ch);
}

//* Input names into the list
void enter(void){
    int i;

    //* Find the first free structure
    for (i = 0; i < SIZE; i++)
    {
        if (!*addr_info[i].name)
        {
            break;
        }
    }

    //* I will equal SIZE if the list is full
    if (i == SIZE)
    {
        printf("list full\n");
        return;
    }
    
    //* Enter the information
    printf("name: ");
    gets(addr_info[i].name);

    printf("street: ");
    gets(addr_info[i].street);

    printf("city: ");
    gets(addr_info[i].city);

    printf("state: ");
    gets(addr_info[i].state);

    printf("zip: ");
    gets(addr_info[i].zip);

}

//* Display the list
void display(void){

    for (int i = 0; i < SIZE; i++)
    {
        if (*addr_info[i].name)
        {
            printf("%s\n", addr_info[i].name);
            printf("%s\n", addr_info[i].street);
            printf("%s\n", addr_info[i].city);
            printf("%s\n", addr_info[i].state);
            printf("%s\n", addr_info[i].zip);
        }   
    }
    return;
}

void save(void){
    FILE *fp;
    int i;

    if ((fp=fopen("mailist", "wb"))==NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    for (i = 0; i < SIZE; i++)
    {
        if (*addr_info[i].name)
            if (fwrite(&addr_info[i], sizeof(struct addr), 1, fp)!=1)
        printf("File write error\n");
    }
    fclose(fp);
}

void load(void){
    FILE *fp;
    int i;

    if ((fp=fopen("mailist", "rb"))==NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    init_list();
    for (i = 0; i < SIZE; i++)
    {
        if (fread(&addr_info[i], sizeof(struct addr), 1, fp)!=1)
        {
            if (feof(fp))
            {
                fclose(fp);
                return;
            }
        }

        printf("File read error\n");
    }
}