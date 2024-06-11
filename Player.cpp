#include "Player.h"


//24,1
Player::Player() : Entity(15, 1) {
	cLook = 'P' | COLOR_PAIR(6);
	ammo = 10;
	facingDirection = 0;
	health = 5;
}



void Player::moveUp(WINDOW* levelWindow, int& lastCheckpointY, int& lastCheckpointX) {

	mvwaddch(levelWindow, curLocY, curLocX, ' ');

	curLocY--;
	int ch = mvwinch(levelWindow, curLocY, curLocX);
	//201326680 je top
	if (ch == '#' || ch == 201326680 || ch == ',' || ch == '-' || ch == '|' || ch == '/' || ch == '\\' || ch == '_') {
		curLocY++;

	}//218103872 = cLookStena 
	else if (ch == 218103872) {
		int chSledece = mvwinch(levelWindow, curLocY - 1, curLocX);
		if (chSledece == ' ') {
			mvwaddch(levelWindow, curLocY - 1, curLocX, '@' | COLOR_PAIR(13));
			playMusic::playSound("stoneSlide");
		}
		else {
			curLocY++;
		}
	}//134217793 == Ammo
	else if (ch == 134217793) {
		playMusic::playSound("reload");
		ammo += 5;

	}
	//117440579 == C
	else if (ch == 117440579) {
		playMusic::playSound("checkpoint");

		lastCheckpointY = curLocY;
		lastCheckpointX = curLocX;

	}//83886189 == m
	else if (ch == 83886189) {
		int rnd = rand() % 3 + 5; // Random number between 3 and 8
		playMusic::playSound("m");

		MemoryEater::ReleaseSomeMemory(rnd);
	}//150994987 == +
	else if (ch == 150994987) {
		playMusic::playSound("health");
		health++;
	}
	cLook = 'P' | COLOR_PAIR(6) | A_NORMAL;

	mvwaddch(levelWindow, curLocY, curLocX, cLook);

	facingDirection = 0;

}

void Player::moveDown(WINDOW* levelWindow, int& lastCheckpointY, int& lastCheckpointX)
{
	mvwaddch(levelWindow, curLocY, curLocX, ' ');

	curLocY++;

	int ch = mvwinch(levelWindow, curLocY, curLocX);
	//201326680 je top
	if (ch == '#' || ch == 201326680 || ch == ',' || ch == '-' || ch == '|' || ch == '/' || ch == '\\' || ch == '_') {
		curLocY--;

	}//218103872 = cLookStena jer je chtype tipa
	else if (ch == 218103872) {
		int chSledece = mvwinch(levelWindow, curLocY + 1, curLocX);
		if (chSledece == ' ') {
			mvwaddch(levelWindow, curLocY + 1, curLocX, '@' | COLOR_PAIR(13));
			playMusic::playSound("stoneSlide");

		}
		else {
			curLocY--;
		}
	}
	//134217793 == Ammo
	else if (ch == 134217793) {
		playMusic::playSound("reload");

		ammo += 5;

	}//117440579 == C
	else if (ch == 117440579) {
		playMusic::playSound("checkpoint");

		lastCheckpointY = curLocY;
		lastCheckpointX = curLocX;

	}//83886189 == m
	else if (ch == 83886189) {
		int rnd = rand() % 3 + 5; // Random number between 3 and 8
		playMusic::playSound("m");
		MemoryEater::ReleaseSomeMemory(rnd);
	}//150994987 == +
	else if (ch == 150994987) {
		playMusic::playSound("health");

		health++;
	}
	cLook = 'P' | COLOR_PAIR(6) | A_UNDERLINE;
	mvwaddch(levelWindow, curLocY, curLocX, cLook);

	facingDirection = 2;

}

void Player::moveLeft(WINDOW* levelWindow, int& lastCheckpointY, int& lastCheckpointX)
{
	mvwaddch(levelWindow, curLocY, curLocX, ' ');

	curLocX--;

	int ch = mvwinch(levelWindow, curLocY, curLocX);
	//201326680 je top
	if (ch == '#' || ch == 201326680 || ch == ',' || ch == '-' || ch == '|' || ch == '/' || ch == '\\' || ch == '_') {
		curLocX++;

	}//218103872 = cLookStena jer je chtype tipa
	else if (ch == 218103872) {
		int chSledece = mvwinch(levelWindow, curLocY, curLocX - 1);
		if (chSledece == ' ') {
			mvwaddch(levelWindow, curLocY, curLocX - 1, '@' | COLOR_PAIR(13));
			playMusic::playSound("stoneSlide");

		}
		else {
			curLocX++;
		}
	}//134217793 == Ammo
	else if (ch == 134217793) {
		playMusic::playSound("reload");
		ammo += 5;

	}//117440579 == C

	else if (ch == 117440579) {
		playMusic::playSound("checkpoint");

		lastCheckpointY = curLocY;
		lastCheckpointX = curLocX;

	}//83886189 == m
	else if (ch == 83886189) {
		int rnd = rand() % 3 + 5; // Random number between 3 and 8
		playMusic::playSound("m");
		MemoryEater::ReleaseSomeMemory(rnd);
	}//150994987 == +
	else if (ch == 150994987) {
		playMusic::playSound("health");
		health++;
	}
	cLook = 'P' | COLOR_PAIR(6) | A_LEFT;

	mvwaddch(levelWindow, curLocY, curLocX, cLook);

	facingDirection = 3;

}

void Player::moveRight(WINDOW* levelWindow, int& lastCheckpointY, int& lastCheckpointX)
{
	mvwaddch(levelWindow, curLocY, curLocX, ' ');

	curLocX++;
	int ch = mvwinch(levelWindow, curLocY, curLocX);
	//201326680 je top
	if (ch == '#' || ch == 201326680 || ch == ',' || ch == '-' || ch == '|' || ch == '/' || ch == '\\' || ch == '_') {
		curLocX--;

	}//218103872 = cLookStena jer je chtype tipa
	else if (ch == 218103872) {
		int chSledece = mvwinch(levelWindow, curLocY, curLocX + 1);
		if (chSledece == ' ') {
			mvwaddch(levelWindow, curLocY, curLocX + 1, '@' | COLOR_PAIR(13));
			playMusic::playSound("stoneSlide");

		}
		else {
			curLocX--;
		}
	}//134217793 == Ammo
	else if (ch == 134217793) {
		playMusic::playSound("reload");
		ammo += 5;

	}//117440579 == C
	else if (ch == 117440579) {
		playMusic::playSound("checkpoint");

		lastCheckpointY = curLocY;
		lastCheckpointX = curLocX;

	}//83886189 == m
	else if (ch == 83886189) {
		int rnd = rand() % 3 + 5; // Random number between 3 and 8
		playMusic::playSound("m");
		MemoryEater::ReleaseSomeMemory(rnd);
	}//150994987 == +
	else if (ch == 150994987) {
		playMusic::playSound("health");
		health++;
	}
	cLook = 'P' | COLOR_PAIR(6) | A_RIGHT;

	mvwaddch(levelWindow, curLocY, curLocX, cLook);

	facingDirection = 1;
}


