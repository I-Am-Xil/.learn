//TODO: gcc pdcurses_printw.c -lpdcurses -o pdcurses_printw.exe

#include<curses.h>
#include<string.h>

int main(){

    char msg[] = "just a string";
    int row, col;

    initscr();
    getmaxyx(stdscr, row, col);
    mvprintw(row/2, (col-strlen(msg))/2, "%s", msg);

    mvprintw(row-2, 0, "This screen has %d rows and %d columns\n", row, col);
    printw("Try resizing your window (if posible)and then run this program again");
    refresh();
    getchar();
    endwin();

    return 0;
}