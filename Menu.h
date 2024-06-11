#pragma once
#include <string>
#include "curses.h"

#include "LevelFundamental.h"
#include "Level1.h"
#include "playMusic.h"

using namespace std;

class Menu
{
private:
	int choice;
	int highlight;
	string options[3];
	string nivoi[3];
	int trenutniNivo;
	WINDOW* menuWindow;
	bool enterPressed;
	bool exit;
	//klasa roditelj u koju mogu da se smeste leveli, (upcasting?)
	LevelFundamental* currentLevel;
public:
	Menu();
	void drawMenu();
	void drawMenuBasic();

};
