#pragma once
#include <curses.h>
class Stone
{
public:
	int locX;
	int locY;
	chtype cLook;
	Stone(int locY, int locX);
};

