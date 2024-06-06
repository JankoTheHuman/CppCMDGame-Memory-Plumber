#pragma once
#include "LevelFundamental.h"


class Level1 : public LevelFundamental
{
public:

	Level1();
	void drawLevelWalls();
	void levelLoop();
	void reDrawEntities();
	void updateMemoryLeakInfoBox();

};

