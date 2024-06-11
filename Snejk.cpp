#include "Snejk.h"

Snejk::Snejk(int setY, int setX, int dir) : Entity(setY, setX) {

	facingDirection = dir;
	//health = 1;
	cLook = 'S' | COLOR_PAIR(10);

}


