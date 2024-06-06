#ifndef EXCLUDED


#include <curses.h>

int main() {
	int x = 1, y = 1;
	//Initialize the PDCurses library, allocates memory etc.
	initscr();

	//prints a string(const * char) to the window(change is immediate?)
	printw("asd");
	int a = 10;
	printw("\n%d\n", a);


	//moves the cursor to specified location
	move(y, x);

	//moves and prints to the location
	mvprintw(y, x, "Henlo");

	//clears the screen
	clear();

	//refreshes the screen to match what's in memory. Imagine a virtual screen that
	// 	gets populated by printw(), mvprintw(), addch(), etc. and refresh puts it on 
	//	physical screen
	refresh();

	//returns int value of key pressed
	int b = getch();

	// End the PDCurses session, dealocates memory, etc.
	endwin();


	//WINDOWS variable (pointer), creates a window variable  (height, width, y_coordinate, x_coordinate)
	WINDOW* win = newwin(10, 10, y, x);

	//this is how you display where you want the window to appear relative to outside window, and creates 
	//	a nice window border
	//box has to be before any wprintw() cause box will overwrite text, so box is writing function
	box(win, y, x);

	// this is how you print inside of the window
	wprintw(win, "Henlo");

	//this refreshes only said window(i guess it reduces load on performance),
	// before putting WINDOW main window needs to be refreshed, and to show it wrefersh has to be called after
	wrefresh(win);


	//takes a window, cursor and what to print in it
	mvwprintw(win, y, x, "HENLO");


	//makes it so user inputs aren't visible on the screen, its put after initscr() most of the times
	noecho();


}

#endif