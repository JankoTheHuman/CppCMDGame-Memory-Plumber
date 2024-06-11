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
	int facingDirection;


	Entity(int setY, int setX);



};

