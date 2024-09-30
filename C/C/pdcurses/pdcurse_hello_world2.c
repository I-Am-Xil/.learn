#include <curses.h>

int main()
{
    WINDOW* wnd = initscr();
    wprintw(wnd, "Hello world!");
    refresh();
    endwin();
    return 0;
}

/*
int main()
{
    SCREEN* term = newterm(NULL, stdout, stdin);
    set_term(term);
    wprintw(stdscr, "Hello world!"); // the program terminates here
    refresh();
    endwin();
    return 0;
}
*/