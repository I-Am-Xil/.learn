//TODO: gcc pdcurses_attr.c -lpdcurses -o pdcurses_attr.exe

#include<curses.h>

int main(){

    initscr();
    start_color();
    
    //*init_pair(id, text, background)
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    printw("A Big string which i didn't care to type fully");

    //*chgat(char-count, attr_t, id, NULL)
    mvchgat(0, 0, -1, A_REVERSE, 1, NULL);

    refresh();
    getchar();
    endwin();

    return 0;
}