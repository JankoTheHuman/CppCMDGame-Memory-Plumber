#include "Top.h"

Top::Top(int setY, int setX, int dir) : Entity(setY, setX) {

	health = 9999;
	facingDirection = dir;
	cLook = 'X' | COLOR_PAIR(12);
}

void Top::moveUp(WINDOW* levelWindow)
{
}

void Top::moveDown(WINDOW* levelWindow)
{
}

void Top::moveRight(WINDOW* levelWindow)
{
}

void Top::moveLeft(WINDOW* levelWindow)
{
}

void Top::createBullet()
{
	//listaMetkova.emplace_back(new Bullet(p->curLocY, p->curLocX, p->facingDirection));
}
