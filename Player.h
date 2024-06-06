#pragma once
#include "Entity.h"
#include "curses.h"

class Player : public Entity
{
public:

	Player();
	int ammo;



	void moveUp(WINDOW* levelWindow);
	void moveDown(WINDOW* levelWindow);
	void moveLeft(WINDOW* levelWindow);
	void moveRight(WINDOW* levelWindow);


};

