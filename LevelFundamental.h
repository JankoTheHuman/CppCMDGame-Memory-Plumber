#pragma once
#include "curses.h"
#include "Player.h"
#include "MemoryEater.h"
#include "Stone.h"
#include <vector>
#include "Top.h"
#include "Bullet.h"
#include "playMusic.h"
#include <iostream>
#include "Snejk.h"
#include "Demon.h"
using namespace std;
class LevelFundamental
{
private:


protected:
	WINDOW* levelWindow;
	WINDOW* memoryEaterWindow;
	WINDOW* playerStatsWindow;
	WINDOW* howToPlayWindow;

public:
	vector<Top> listaTopova;
	vector<Bullet*> listaMetkova;
	vector<Snejk*> listaZmija;
	vector<Demon*> listaDemona;


	int ciklusStvaranjaMetkovaTop;
	int count;
	virtual void updateBullets() = 0;
	chtype cLookStena;
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
	virtual void drawStones() = 0;
	virtual void drawCannons() = 0;
	virtual void updateLivesLeft() = 0;
	virtual void updateAmmoScreen() = 0;
	virtual void updateCannons() = 0;
	virtual void drawAmmo() = 0;
	virtual void drawHealth() = 0;
	virtual void drawCheckpoint() = 0;
	virtual void drawLevers() = 0;
	bool toInput;
	int choice;
	int tezina;
	bool blinkAmmo;
	int lasCheckPointX;
	int lasCheckPointY;

};

