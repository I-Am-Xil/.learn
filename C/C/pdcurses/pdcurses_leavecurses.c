//TODO: gcc pdcurses_leavecurses.c -lpdcurses -o pdcurses_leavecurses.exe

#include <curses.h>

int main()
{	
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!\n");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	def_prog_mode();		/* Save the tty modes		  */
	endwin();			/* End curses mode temporarily	  */
	system("/bin/sh");		/* Do whatever you like in cooked mode */
	reset_prog_mode();		/* Return to the previous tty mode*/
					/* stored by def_prog_mode() 	  */
	refresh();			/* Do refresh() to restore the	  */
					/* Screen contents		  */
	printw("Another String\n");	/* Back to curses use the full    */
	refresh();			/* capabilities of curses	  */
	endwin();			/* End curses mode		  */

	return 0;
}

/**
 *!This function can be used to make the cursor invisible. The parameter to this function should be
 **    curs_set()
 *     0 : invisible      or
 *     1 : normal    or
 *     2 : very visible.
*/