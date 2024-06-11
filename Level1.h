#pragma once
#include "LevelFundamental.h"
#include "Player.h"
#include "Top.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
#include "Snejk.h"
#include <random>
#include <ctime>

class Level1 : public LevelFundamental
{
public:
	std::mt19937 rng;
	int previousAmmo;
	int previousHealth;
	bool randomAsserted;
	int bossHp;
	bool leverCorridorPulled;
	bool bossLeverPulled;
	bool lever1Pulled;
	bool lever2Pulled;
	bool lever3Pulled;
	bool blinkBoss;

	Level1(int nivo);
	void drawLevelWalls();
	void levelLoop();
	void reDrawEntities();
	void updateMemoryLeakInfoBox();
	void drawStones();
	void drawCannons();
	void ispuniListuTopova();
	void removeWallsBoss();
	void updateBullets();
	void updateLivesLeft();
	void updateAmmoScreen();
	void updateCannons();
	void drawAmmo();
	void drawHealth();
	void drawCheckpoint();
	void drawLevers();
	void checkLevers();
	void drawMemFrags();
	void ispuniListuZmija();
	void ispuniListuDemona();
	void updateDemons();
	void updateZmije();
	void pullLever1();
	void pullLever2();
	void pullLever3();
	void corridorTrap();
	void updateBossHp();
	void bossKillScreen();


};

