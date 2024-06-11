#include "Demon.h"

Demon::Demon(int setY, int setX) : Entity(setY, setX) {

	cLook = 'D' | COLOR_PAIR(11);

}