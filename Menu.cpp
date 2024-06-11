#include "Menu.h"

Menu::Menu()
{
	choice = 0;
	exit = false;
	highlight = 0;
	options[0] = "   POCNI IGRU   ";
	options[1] = "<-  TEZINA 1  ->";
	options[2] = "     IZADJI     ";

	nivoi[0] = "<-  TEZINA 1  ->";
	nivoi[1] = "<-  TEZINA 2  ->";
	nivoi[2] = "<-  TEZINA 3  ->";

	trenutniNivo = 0;

	menuWindow = newwin(LINES, COLS, 0, 0);
	enterPressed = false;
	box(menuWindow, '*', '~');
	refresh();
	wrefresh(menuWindow);
	keypad(menuWindow, true);


}

void Menu::drawMenuBasic() {
	
	wattron(menuWindow, COLOR_PAIR(8));

	mvwprintw(menuWindow, 5, 10, "     '||    ||'                                                '||''|.  '||                      '||                      ");
	mvwprintw(menuWindow, 6, 10, "      |||  |||    ....  .. .. ..     ...   ... ..  .... ...     ||   ||  ||  ... ...  .. .. ..    || ...    ....  ... ..  ");
	mvwprintw(menuWindow, 7, 10, "      |'|..'||  .|...||  || || ||  .|  '|.  ||' ''  '|.  |      ||...|'  ||   ||  ||   || || ||   ||'  || .|...||  ||' '' ");
	mvwprintw(menuWindow, 8, 10, "      | '|' ||  ||       || || ||  ||   ||  ||       '|.|       ||       ||   ||  ||   || || ||   ||    | ||       ||     ");
	mvwprintw(menuWindow, 9, 10, "     .|. | .||.  '|...' .|| || ||.  '|..|' .||.       '|       .||.     .||.  '|..'|. .|| || ||.  '|...'   '|...' .||.    ");
	mvwprintw(menuWindow, 10, 10, "                                                   .. |                                                                ");
	mvwprintw(menuWindow, 11, 10, "                                                    ''                                                                 ");

	wattroff(menuWindow, COLOR_PAIR(8));




	mvwprintw(menuWindow, 31, 2, "Janko Veselinovic 2024");
	mvwprintw(menuWindow, 31, 116, "jankoveselinovic997@gmail.com");


	wrefresh(menuWindow);

}


void Menu::drawMenu()
{




	int j;


	//ceo program se vrti u ovoj petlji, unutrasnji while je za meni, spoljasnji za kreiranje
	//  levela nakon cega oni preuzimaju crtanje
	while (1) {




		if (exit) {
			break;
		}

		drawMenuBasic();
		box(menuWindow, '*', '~');



		enterPressed = false;

		//provera za izbor opcije u meniju
		while (!enterPressed) {



			for (int i = 0;i < 3;i++) {
				if (i == highlight) {
					wattron(menuWindow, A_REVERSE);
				}
				j = i * 2;

				if (i == 1) {
					mvwprintw(menuWindow, (LINES / 2) + j, COLS / 2 - 10, nivoi[trenutniNivo].c_str());

				}
				else {
					if (i == 0) {
						wattron(menuWindow, COLOR_PAIR(1));
					}
					else if (i == 2) {
						wattron(menuWindow, COLOR_PAIR(3));

					}

					mvwprintw(menuWindow, (LINES / 2) + j, COLS / 2 - 10, options[i].c_str());
				}

				wattroff(menuWindow, COLOR_PAIR(1));
				wattroff(menuWindow, COLOR_PAIR(3));
				wattroff(menuWindow, A_REVERSE);


			}

			//ceka na input strelica ili entera 0.2 sekunde zbog halfdelay(2)
			choice = wgetch(menuWindow);

			switch (choice) {
			case KEY_UP:

				if (highlight == 0) {
					highlight = 2;
					break;
				}
				highlight--;
				break;
			case KEY_DOWN:
				if (highlight == 2) {
					highlight = 0;
					break;
				}
				highlight++;
				break;
			case KEY_RIGHT:
				if (highlight == 1) {
					//level pick
					if (trenutniNivo == 2) {
						trenutniNivo = 0;
						break;
					}
					trenutniNivo++;
				}
				break;
			case KEY_LEFT:
				if (highlight == 1) {
					//level pick
					if (trenutniNivo == 0) {
						trenutniNivo = 2;
						break;
					}
					trenutniNivo--;
				}
				break;
			default:
				break;

			}

			//459 je enter
			if (choice == 459 && (highlight == 2 || highlight == 0)) {
				choice = -1;
				enterPressed = true;
				if (highlight == 2) {
					endwin();

					playMusic::keepPlaying = false;
					exit = true;
				}
				else if (highlight == 0) {
					break;
				}
			}

		}




		//pravljenje levela i ulazenje u njihove metode crtanja, kraj tih metoda je nastavah while(1)
		//  petlje i kasnije while crtanje menija petlje
		if (highlight == 0) {
			//if (trenutniNivo == 0) {
				//trenutniNivo = 0;
			MemoryEater::toLeak = true;
			MemoryEater::StartEatingMemory();
			currentLevel = new Level1(trenutniNivo);
			MemoryEater::ReleaseAllMemory();
			delete currentLevel;
			currentLevel = nullptr;
			//}

		}
	}



}


