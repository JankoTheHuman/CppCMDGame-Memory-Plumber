#pragma once
#include "Entity.h"
#include "curses.h"
#include "playMusic.h"
#include "MemoryEater.h"

class Player : public Entity
{
public:

	Player();
	int ammo;



	void moveUp(WINDOW* levelWindow, int& lastCheckpointY, int& lastCheckpointX);
	void moveDown(WINDOW* levelWindow, int& lastCheckpointY, int& lastCheckpointX);
	void moveLeft(WINDOW* levelWindow, int& lastCheckpointY, int& lastCheckpointX);
	void moveRight(WINDOW* levelWindow, int& lastCheckpointY, int& lastCheckpointX);


};

