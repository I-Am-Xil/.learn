#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    /*create an array of things*/

    char *command[] = {
        "DIR",
        "CHKDSK",
        "TIME",
        "DATE"
    };
    char ch;

    for(;;)
    {
        do
        {
            printf("1: Directory\n");
            printf("2: Check the disk\n");
            printf("3: Set time\n");
            printf("4: Set date\n");
            printf("5: quit\n");
            printf("\nselection: ");
            ch = getche();
            printf("\n");

        } while ((ch < '1') || (ch > '5'));

        if (ch == '5')
        {
            break;
            /*end*/
        }
        
        /*Execute the specified command*/
        system(command[ch-'1']);
    }
    return 0;
}