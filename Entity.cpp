#include "Entity.h"


Entity::Entity(int setY = 0, int setX = 0) {

	health = 1;
	curLocX = setX;
	curLocY = setY;
	died = false;
	cLook = 'N';
	facingDirection = -1;


}
