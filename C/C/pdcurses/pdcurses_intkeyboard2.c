//TODO: gcc pdcurses_intkeyboard2.c -lpdcurses -o pdcurses_intkeyboard2.exe
/**
 * ! Codigo incompleto
 * ! Al resolver desde cero el problema descubrí el error en pdcurses_intkeyboard.c
*/

#include<stdio.h>
#include<curses.h>

#define WIDTH 30
#define HEIGHT 10

char *choices[] = {
        "Choice 1",
        "Choice 2",
        "Choice 3",
        "Choice 4",
        "Exit"
    };

size_t n_choices = sizeof(choices)/sizeof(char *);
int movement_menu();
void print_menu(WINDOW *menu_win, int highlight);



int main(){

    int highlight = 0;

    WINDOW *menu_win;
    int startx = 0;
    int starty = 0;

    initscr();
    clear();
    raw();
    noecho();
    cbreak();

    startx = (80 - WIDTH)/2;
    starty = (22 - HEIGHT)/2;

    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    refresh();

    print_menu(menu_win, highlight);

    refresh();
    getchar();
    endwin();

    return 0;
}

void print_menu(WINDOW *menu_win, int highlight){

    int y = 2;

    box(menu_win, 0, 0);

    for(size_t i = 0; i < n_choices; i++){

        if(highlight == i){
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, 2, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }else{
            mvwprintw(menu_win, y, 2, "%s", choices[i]);
        }
        y++;
    }
    wrefresh(menu_win);
}

/*
int movement_menu(){

    int highlight = 0;
    int c = getchar();

    switch(c){
    case KEY_UP:
        highlight--; 
        break;
    
    case KEY_DOWN:
        highlight++;
        break;

    }

    return highlight;
}
*/