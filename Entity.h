#pragma once
#include "curses.h"
class Entity
{
public:
	int health;
	int curLocX;
	int curLocY;
	bool died;
	chtype cLook;

	Entity();

	virtual void moveUp(WINDOW* levelWindow) = 0;
	virtual void moveDown(WINDOW* levelWindow) = 0;
	virtual void moveLeft(WINDOW* levelWindow) = 0;
	virtual void moveRight(WINDOW* levelWindow) = 0;

};

