#pragma once
#include "Entity.h"

class Top :public Entity
{
public:
	Top(int locY, int locX, int dir);
	void moveUp(WINDOW* levelWindow);
	void moveDown(WINDOW* levelWindow);
	void moveRight(WINDOW* levelWindow);
	void moveLeft(WINDOW* levelWindow);

	void createBullet();
};

