#pragma once
#include "curses.h"
class Bullet
{
public:
	int locY;
	int locX;
	int facingDirection;
	chtype cLook;
	Bullet(int locY, int locX, int dir);

};

