#include "LevelFundamental.h"



LevelFundamental::LevelFundamental()
{	//(height, width, y_coordinate, x_coordinate)

	levelWindow = newwin(LINES - 7, COLS - 30, 0, 0);
	box(levelWindow, '#', '#');
	memoryEaterWindow = newwin(5, COLS - (COLS - 30), 0, COLS - 30);
	box(memoryEaterWindow, 0, 0);
	howToPlayWindow = newwin(LINES - 12, COLS - (COLS - 30), 5, COLS - 30);
	box(howToPlayWindow, 0, 0);
	playerStatsWindow = newwin(7, COLS, LINES - 7, 0);
	box(playerStatsWindow, 0, 0);
	keypad(levelWindow, true);

	//nodelay(levelWindow, true);
	//wtimeout(levelWindow, 50);

	p = new Player();
	won = false;
	input = -2;
	blink = false;
	cLookStena = '@' | COLOR_PAIR(13);

}

void LevelFundamental::clearAllWindows() {
	this_thread::sleep_for(chrono::milliseconds(1000));

	ungetch('n');
	werase(levelWindow);
	wrefresh(levelWindow);

	werase(howToPlayWindow);
	wrefresh(howToPlayWindow);

	werase(playerStatsWindow);
	wrefresh(playerStatsWindow);

	werase(memoryEaterWindow);
	wrefresh(memoryEaterWindow);
}

void LevelFundamental::drawEverythingButLevelWin()
{



	//memoryEaterWindow
	wattron(memoryEaterWindow, COLOR_PAIR(5));
	mvwprintw(memoryEaterWindow, 1, 5, "Memorije procurelo:");
	mvwprintw(memoryEaterWindow, 2, 10, ".");
	mvwprintw(memoryEaterWindow, 3, 22, ".");
	mvwprintw(memoryEaterWindow, 2, 25, "/");
	mvwprintw(memoryEaterWindow, 0, 26, ";");
	mvwprintw(memoryEaterWindow, 3, 3, "[");
	mvwprintw(memoryEaterWindow, 4, 12, "}");
	mvwprintw(memoryEaterWindow, 5, 21, "\"");
	mvwprintw(memoryEaterWindow, 1, 3, "\\");
	wattroff(memoryEaterWindow, COLOR_PAIR(5));




	//howToPlayWindow
	mvwprintw(howToPlayWindow, 1, 5, "Strelice za kretanje");

	wattron(howToPlayWindow, COLOR_PAIR(6));
	mvwprintw(howToPlayWindow, 2, 10, "    ^    ");
	mvwprintw(howToPlayWindow, 3, 10, "    |    ");
	mvwprintw(howToPlayWindow, 4, 10, "<-  P  ->");
	mvwprintw(howToPlayWindow, 5, 10, "    |    ");
	mvwprintw(howToPlayWindow, 6, 10, "    V    ");
	mvwprintw(howToPlayWindow, 7, 8, "F");
	wattroff(howToPlayWindow, COLOR_PAIR(6));

	mvwprintw(howToPlayWindow, 7, 10, "= pucanje");

	wattron(howToPlayWindow, COLOR_PAIR(8));
	mvwprintw(howToPlayWindow, 7, 20, "*");
	wattroff(howToPlayWindow, COLOR_PAIR(8));

	wattron(howToPlayWindow, COLOR_PAIR(7));
	mvwprintw(howToPlayWindow, 8, 8, "C");
	wattroff(howToPlayWindow, COLOR_PAIR(7));

	mvwprintw(howToPlayWindow, 8, 10, "= checkpoint");

	wattron(howToPlayWindow, COLOR_PAIR(9));
	mvwprintw(howToPlayWindow, 10, 8, "+");
	wattroff(howToPlayWindow, COLOR_PAIR(9));

	mvwprintw(howToPlayWindow, 10, 10, "= zivot");

	wattron(howToPlayWindow, COLOR_PAIR(8));
	mvwprintw(howToPlayWindow, 9, 8, "A");
	wattroff(howToPlayWindow, COLOR_PAIR(8));

	mvwprintw(howToPlayWindow, 9, 10, "= municija");

	wattron(howToPlayWindow, COLOR_PAIR(10));
	mvwprintw(howToPlayWindow, 12, 5, "S");
	wattroff(howToPlayWindow, COLOR_PAIR(10));

	mvwprintw(howToPlayWindow, 12, 7, "= SNAKE (horiz-vert)");

	wattron(howToPlayWindow, COLOR_PAIR(11));
	mvwprintw(howToPlayWindow, 13, 5, "D");
	wattroff(howToPlayWindow, COLOR_PAIR(11));

	mvwprintw(howToPlayWindow, 13, 7, "= DEMON (random)");

	wattron(howToPlayWindow, COLOR_PAIR(12));
	mvwprintw(howToPlayWindow, 14, 5, "X");
	wattroff(howToPlayWindow, COLOR_PAIR(12));

	mvwprintw(howToPlayWindow, 14, 7, "= TOP (neunistiv)");


	mvwaddch(howToPlayWindow, 16, 5, '@' | COLOR_PAIR(13));
	mvwprintw(howToPlayWindow, 16, 6, " = pomerljiva stena");


	wattron(howToPlayWindow, COLOR_PAIR(5));
	mvwprintw(howToPlayWindow, 17, 5, "m");
	wattroff(howToPlayWindow, COLOR_PAIR(5));

	mvwprintw(howToPlayWindow, 17, 7, "= FRAGMENT memorije");



	wattron(howToPlayWindow, COLOR_PAIR(6));
	mvwprintw(howToPlayWindow, 18, 5, "l");
	wattroff(howToPlayWindow, COLOR_PAIR(6));

	mvwprintw(howToPlayWindow, 18, 7, "= poluga");



	//playerStatsWindow
	wattron(playerStatsWindow, COLOR_PAIR(8));
	mvwprintw(playerStatsWindow, 2, 10, "Municija:");
	mvwprintw(playerStatsWindow, 4, 13, "10");
	wattroff(playerStatsWindow, COLOR_PAIR(8));


	wattron(playerStatsWindow, COLOR_PAIR(9));
	mvwprintw(playerStatsWindow, 2, 30, "Zivota:");
	mvwprintw(playerStatsWindow, 4, 33, "5");
	wattroff(playerStatsWindow, COLOR_PAIR(9));




	mvwprintw(playerStatsWindow, 1, 90, "Misija:");
	mvwprintw(playerStatsWindow, 2, 45, "Vas svet je napadnut od strane zlog virusa koji zauzima i curi operativnu memoriju svuda po svetu!");
	mvwprintw(playerStatsWindow, 3, 60, "Vi ste vodoinstalater (Plumber) i Vas zadatak je da zaustavite curenje!");
	mvwprintw(playerStatsWindow, 4, 60, "Ako ne zaustavite curenje na vreme svet oko Vas ce prestati da postoji!");


	mvwprintw(playerStatsWindow, 5, 120, "ESC -> Povratak na meni");


	wrefresh(levelWindow);
	wrefresh(memoryEaterWindow);
	wrefresh(howToPlayWindow);
	wrefresh(playerStatsWindow);








}
