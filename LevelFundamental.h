#pragma once
#include "curses.h"
#include "Player.h"
#include "MemoryEater.h"

class LevelFundamental
{
private:


protected:
	WINDOW* levelWindow;
	WINDOW* memoryEaterWindow;
	WINDOW* playerStatsWindow;
	WINDOW* howToPlayWindow;

public:
	bool won;
	int input;
	Player* p;
	LevelFundamental();
	void clearAllWindows();
	// Cista virtuelna metoda koja cini klasu apstraktnom, Level1/2.. moraju da overraduju ove metode
	virtual void reDrawEntities() = 0;
	virtual void drawLevelWalls() = 0;
	virtual void updateMemoryLeakInfoBox() = 0;
	bool blink;
	void drawEverythingButLevelWin();
};

