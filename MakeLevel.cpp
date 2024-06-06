#include "MakeLevel.h"
#include "Level1.h"

int MakeLevel::currentLevelID = 0;
LevelFundamental* MakeLevel::currentLevel = new Level1();
Menu* MakeLevel::menu = new Menu();

void MakeLevel::CreateLevel(int lv)
{

	delete menu;
	delete currentLevel;

	switch (lv) {
	case 0:
		menu = new Menu();
		break;
	case 1:
		currentLevel = new Level1();
		currentLevelID = 1;
		break;
	}
}

void MakeLevel::DeleteLevel(int lv)
{
}
