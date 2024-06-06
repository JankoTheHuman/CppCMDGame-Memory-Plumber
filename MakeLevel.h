#pragma once
#include <curses.h>

#include "LevelFundamental.h"
#include "Menu.h"

class MakeLevel
{

public:

	MakeLevel() = delete;
	static LevelFundamental* currentLevel;
	static Menu* menu;
	static int currentLevelID;
	static void CreateLevel(int lv);
	static void DeleteLevel(int lv);

};

