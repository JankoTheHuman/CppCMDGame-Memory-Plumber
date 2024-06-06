#include "Player.h"



Player::Player() {
	cLook = 'P' | COLOR_PAIR(6);
	ammo = 5;
}



void Player::moveUp(WINDOW* levelWindow) {

	mvwaddch(levelWindow, curLocY, curLocX, ' ');

	curLocY--;
	int ch = mvwinch(levelWindow, curLocY, curLocX);
	if (ch == '#') {
		curLocY++;

	}

}

void Player::moveDown(WINDOW* levelWindow)
{
	mvwaddch(levelWindow, curLocY, curLocX, ' ');

	curLocY++;

	int ch = mvwinch(levelWindow, curLocY, curLocX);
	if (ch == '#') {
		curLocY--;

	}

}

void Player::moveLeft(WINDOW* levelWindow)
{
	mvwaddch(levelWindow, curLocY, curLocX, ' ');

	curLocX--;

	int ch = mvwinch(levelWindow, curLocY, curLocX);
	if (ch == '#') {
		curLocX++;

	}

}

void Player::moveRight(WINDOW* levelWindow)
{
	mvwaddch(levelWindow, curLocY, curLocX, ' ');

	curLocX++;
	int ch = mvwinch(levelWindow, curLocY, curLocX);
	if (ch == '#') {
		curLocX--;

	}
}


