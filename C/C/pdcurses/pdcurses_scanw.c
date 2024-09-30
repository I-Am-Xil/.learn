//TODO: gcc pdcurses_scanw.c -lpdcurses -o pdcurses_scanw.exe

#include<curses.h>
#include<string.h>

int main(){

    char msg[] = "Enter a string: ";
    char str[80];
    int row, col;

    initscr();
    getmaxyx(stdscr, row, col);
    mvprintw(row/2, (col-strlen(msg))/2, "%s", msg);

    getstr(str);
    mvprintw(LINES - 2, 0, "You entered: %s", str);
    refresh();
    getchar();
    endwin();

    return 0;
}