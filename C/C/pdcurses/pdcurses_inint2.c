//TODO: gcc pdcurses_inint2.c -lpdcurses -o pdcurses_inint2.exe

#include<curses.h>
#include<ctype.h>


int main(){
    char activate;
    int ch;
    initscr();
    raw();
    noecho();
    while (activate != 'a')
    {
        clear();
        printw("Press 'A' to initiate\n");
        refresh();
        activate = getch();
        activate = tolower(activate);
        keypad(stdscr, FALSE);
    }

    clear();
    keypad(stdscr, TRUE);

    printw("Type any character to see it in bold\n");
    ch = getch();

    if(ch == KEY_F(1)) printw("F1 key pressed");
    else{
        printw("The pressed key is: ");
        //* Attron no aparace en la documentacion pero es mas sencilla que attr_on(chtype, void*);
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }

    refresh();
    endwin();

    return 0;
}