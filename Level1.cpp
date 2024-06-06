#include "Level1.h"
#include "Player.h"

Level1::Level1()
{
	drawEverythingButLevelWin();
	drawLevelWalls();

	p->curLocY = 24;
	p->curLocX = 1;

	mvwaddch(levelWindow, p->curLocY, p->curLocX, p->cLook);

	levelLoop();
}

void Level1::reDrawEntities() {

	mvwaddch(levelWindow, p->curLocY, p->curLocX, p->cLook);



	wrefresh(levelWindow);
	updateMemoryLeakInfoBox();

}

void Level1::updateMemoryLeakInfoBox()
{
	const char* mem = MemoryEater::getMbOfAllocatedMemory();

	if (blink) {

		wattron(memoryEaterWindow, A_STANDOUT);
		mvwaddstr(memoryEaterWindow, 3, 12, mem);
		wattroff(memoryEaterWindow, A_STANDOUT);
		blink = !blink;
	}
	else {
		mvwaddstr(memoryEaterWindow, 3, 12, mem);
		blink = !blink;

	}


	mvwaddstr(memoryEaterWindow, 3, 15, " MB");

	wrefresh(memoryEaterWindow);
}




void Level1::drawLevelWalls()
{
	//########################################     ######################################################################################################################
	wmove(levelWindow, 1, 1); waddstr(levelWindow, "              #                                                                       #                            ");
	wmove(levelWindow, 2, 1); waddstr(levelWindow, "              #                                                                       #,-------------------------, ");
	wmove(levelWindow, 3, 1); waddstr(levelWindow, "              #                  #     #              ##                              #|  /-------------------\\  | ");
	wmove(levelWindow, 4, 1); waddstr(levelWindow, "              #                  #     #                   #               ##         #| | CURENJE U TOKU >:)  | | ");
	wmove(levelWindow, 5, 1); waddstr(levelWindow, "              #                  #     #                #       #                 #   #| |      __     __      | | ");
	wmove(levelWindow, 6, 1); waddstr(levelWindow, "              #                  #     #                     ##      #         #      #| |     ( (_____) )     | | ");
	wmove(levelWindow, 7, 1); waddstr(levelWindow, "######  #######                  #     #                 ##              #            #| |      [ X  X  ]      | | ");
	wmove(levelWindow, 8, 1); waddstr(levelWindow, "     #        ##                 #     #                                              #| |       \\ ..  /       | | ");
	wmove(levelWindow, 9, 1); waddstr(levelWindow, "     ########  ##                #     #           ##            #                    #|  \\_______\\___/________/ |");
	wmove(levelWindow, 10, 1);waddstr(levelWindow, "            ##  ##               #     #                              ##              #|_________________________| ");
	wmove(levelWindow, 11, 1);waddstr(levelWindow, "             ##  ##              #     #    #    #                            # ##    # \\______   [  ]   _______/ ");
	wmove(levelWindow, 12, 1);waddstr(levelWindow, "######        ##  ##             #     #     ####                 ##                  #       /___________\\       ");
	wmove(levelWindow, 13, 1);waddstr(levelWindow, "     #         ##  ##            #     #                                              #############################");
	wmove(levelWindow, 14, 1);waddstr(levelWindow, "     #   #      ##  ##          ##     ##                                                                          ");
	wmove(levelWindow, 15, 1);waddstr(levelWindow, "     #   #       ##  ##         ##     ##              #######################      #                              ");
	wmove(levelWindow, 16, 1);waddstr(levelWindow, "     #   #        ##  ##       ##       ##                                          #                 #############");
	wmove(levelWindow, 17, 1);waddstr(levelWindow, "     #   ##                   ##         ##                             #           #                              ");
	wmove(levelWindow, 18, 1);waddstr(levelWindow, "     #    #########           #############                                         #                              ");
	wmove(levelWindow, 19, 1);waddstr(levelWindow, "     ##            #                                          #                     #                              ");
	wmove(levelWindow, 20, 1);waddstr(levelWindow, "      #############################################################################################        ########");
	wmove(levelWindow, 21, 1);waddstr(levelWindow, "       #           #                               ##          ##                                                  ");
	wmove(levelWindow, 22, 1);waddstr(levelWindow, "       #           #           #      ##          ##          ##                                                   ");
	wmove(levelWindow, 23, 1);waddstr(levelWindow, "                   #           #       ##        ##                                                                ");
	wmove(levelWindow, 24, 1);waddstr(levelWindow, "       #              #        #        ##                 ##                                                      ");
	//########################################     ######################################################################################################################




	wrefresh(levelWindow);
}




void Level1::levelLoop() {


	while (true) {


		if (p->health == 0) {
			p->died = true;
			break;
		}
		else if (won) {
			break;
		}       //27 == ESC
		else if (input == 27) {
			clearAllWindows();

			break;
		}



		input = wgetch(levelWindow);



		switch (input) {
		case KEY_UP:

			p->moveUp(levelWindow);
			reDrawEntities();
			break;
		case KEY_DOWN:
			p->moveDown(levelWindow);
			reDrawEntities();
			break;
		case KEY_LEFT:
			p->moveLeft(levelWindow);
			reDrawEntities();
			break;
		case KEY_RIGHT:
			p->moveRight(levelWindow);
			reDrawEntities();
			break;
		case 'f':
			break;
			//implement shooting
		default:
			reDrawEntities();
			break;

		}



	}
}

