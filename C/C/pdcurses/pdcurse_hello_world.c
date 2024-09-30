/*
TODO: Se debe compilar de la siguiente forma:
TODO: gcc pdcurse_hello_world.c -lpdcurses -o pdcurse_hello_world.exe
*/
#include<curses.h>
#include<stdlib.h>

int main(){
    //*Inicia modo ventana
    initscr();
    printw("Hello world!\n");
    refresh();
    endwin();

    system("PAUSE>nul");
    return 0;
}