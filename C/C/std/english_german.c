/**
 * TODO: A very simple English to German translator
 */

#include <stdio.h>
#include <string.h>

char trans[][20] = {
    "is", "ist",
    "this", "das",
    "not", "nicht",
    "a", "ein",
    "book", "buch",
    "apple", "apfel",
    "i", "ich",
    "bread", "brot",
    "drive", "fahren",
    "to", "zu",
    "buy", "kaufen"
};

char imput [80];
char word[80];
char *p;

/**
 * *this function will read the next word from the imput array.
 * *Each word is assumed to be separated by a space o the null terminator.
 * *No other punctuation is allowed.
 * *the word returned will be a null length string when the end of the input string is reached.
*/
void get_word()
{
    char *q;
    
    /*reload addres of word each time function is called*/
    q = word;

    /*get next word*/
    while (*p && *p != ' ') /*mientras *p sea diferente de nulo y diferente de ' '*/
    {
        *q = *p; /*se hace *q igual a *p, así guardamos cada palabra en el arreglo word*/
        p++;
        q++;
    }
    if (*p == ' ') p++;
    *q = '\0'; /*null terminate each word*/
}

/*this function returns the location of a match between the string pointed to by s and tha trans array*/
int lookup(char *s)
{
    int i;

    for ( i = 0; *trans[i]; i++)
    {
        if (!strcmp(trans[i], s))
        {
            break;
        }
    }

    if (*trans[i])
    {
        return i;
    }else{
        return -1;
    }
}

int main()
{
    int loc;

    printf("Enter English sentence: ");
    gets(imput);
    p = imput; /*give p the address of the array input */
    printf("Rough German translation: ");

    get_word(); /*get the first word*/

    /**
     * TODO: This is the main loop. It reads a word at a time from the imput array and translates each word into german*/
    do{
        /*find the index of the English word in trans*/
        loc = lookup(word);

        /*printf the german if a match is found*/
        if (loc != -1)
        {
             printf("%s ", trans[loc+1]);
        }else{
            printf("<unknown> ");
        }
        
        get_word(); /*get next word*/
    }while (*word);
    
    return 0;
}
