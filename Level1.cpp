#include "Level1.h"

using namespace std;


Level1::Level1(int nivo) : rng(static_cast<unsigned int>(std::time(nullptr)))
{
	bossHp = 9;
	randomAsserted = false;
	drawEverythingButLevelWin();
	drawLevelWalls();
	ciklusStvaranjaMetkovaTop = 2;
	count = 0;
	switch (nivo) {
	case 0:
		tezina = 150;
		break;
	case 1:
		tezina = 100;
		break;
	case 2:
		tezina = 50;
		break;
	default:
		break;

	}
	blinkAmmo = false;
	blinkBoss = false;

	//add player
	mvwaddch(levelWindow, p->curLocY, p->curLocX, p->cLook);
	//add stones
	drawStones();

	ispuniListuTopova();
	ispuniListuZmija();
	ispuniListuDemona();



	drawCannons();
	drawAmmo();
	drawHealth();
	drawCheckpoint();
	drawLevers();
	drawMemFrags();

	toInput = true;
	lasCheckPointX = 1;
	lasCheckPointY = 24;

	previousHealth = p->health;
	previousAmmo = p->ammo;

	leverCorridorPulled = false;
	bossLeverPulled = false;
	lever1Pulled = false;
	lever2Pulled = false;
	lever3Pulled = false;




	levelLoop();




}

void Level1::drawMemFrags() {

	wattron(levelWindow, COLOR_PAIR(5));
	mvwprintw(levelWindow, 21, 46, "m");
	mvwprintw(levelWindow, 22, 46, "m");
	mvwprintw(levelWindow, 23, 46, "m");
	mvwprintw(levelWindow, 24, 46, "m");

	mvwprintw(levelWindow, 7, 26, "m");
	mvwprintw(levelWindow, 8, 24, "m");
	mvwprintw(levelWindow, 8, 28, "m");
	mvwprintw(levelWindow, 9, 27, "m");
	mvwprintw(levelWindow, 9, 25, "m");

	mvwprintw(levelWindow, 16, 84, "m");
	mvwprintw(levelWindow, 17, 83, "m");
	mvwprintw(levelWindow, 18, 82, "m");

	mvwprintw(levelWindow, 19, 31, "m");
	mvwprintw(levelWindow, 19, 43, "m");





	wattroff(levelWindow, COLOR_PAIR(5));
}

void Level1::drawAmmo() {
	wattron(levelWindow, COLOR_PAIR(8));

	mvwprintw(levelWindow, 13, 1, "A");
	mvwprintw(levelWindow, 13, 5, "A");

	mvwprintw(levelWindow, 21, 100, "A");
	mvwprintw(levelWindow, 21, 107, "A");

	mvwprintw(levelWindow, 24, 100, "A");
	mvwprintw(levelWindow, 24, 107, "A");

	mvwprintw(levelWindow, 8, 1, "A");
	mvwprintw(levelWindow, 8, 2, "A");
	mvwprintw(levelWindow, 9, 1, "A");



	wattroff(levelWindow, COLOR_PAIR(8));
}

void Level1::drawHealth()
{
	chtype h = '+' | COLOR_PAIR(9);

	mvwaddch(levelWindow, 21, 59, h);
	mvwaddch(levelWindow, 14, 3, h);
	mvwaddch(levelWindow, 22, 82, h);
	mvwaddch(levelWindow, 11, 3, h);
	mvwaddch(levelWindow, 15, 104, h);
	mvwaddch(levelWindow, 1, 18, h);
	mvwaddch(levelWindow, 18, 63, h);
	mvwaddch(levelWindow, 10, 53, h);
	mvwaddch(levelWindow, 7, 70, h);



}

void Level1::drawCheckpoint() {

	wattron(levelWindow, COLOR_PAIR(7));
	mvwprintw(levelWindow, 23, 63, "C");
	mvwprintw(levelWindow, 14, 87, "C");
	mvwprintw(levelWindow, 17, 19, "C");
	mvwprintw(levelWindow, 24, 88, "C");



	wattroff(levelWindow, COLOR_PAIR(7));

}

void Level1::drawLevers()
{
	wattron(levelWindow, COLOR_PAIR(6));
	//corridorLever
	mvwprintw(levelWindow, 17, 37, "l");
	//1
	mvwprintw(levelWindow, 24, 115, "l");
	//2
	mvwprintw(levelWindow, 19, 19, "l");
	//3
	mvwprintw(levelWindow, 1, 7, "l");
	wattroff(levelWindow, COLOR_PAIR(6));


}

void Level1::checkLevers()
{
	//100663404 == lever


	int leverCorridorLoc = mvwinch(levelWindow, 17, 37);

	if (leverCorridorLoc != 100663404 && !leverCorridorPulled) {
		corridorTrap();
		leverCorridorPulled = true;
	}
	int bossLeverLoc = mvwinch(levelWindow, 1, 37);

	if (bossLeverLoc != 100663404 && !bossLeverPulled && leverCorridorPulled) {
		bossLeverPulled = true;
		removeWallsBoss();

	}
	int lever1Loc = mvwinch(levelWindow, 24, 115);

	if (lever1Loc != 100663404 && !lever1Pulled) {
		pullLever1();
		lever1Pulled = true;

	}
	int lever2Loc = mvwinch(levelWindow, 19, 19);

	if (lever2Loc != 100663404 && !lever2Pulled) {
		pullLever2();
		lever2Pulled = true;
	}
	int lever3Loc = mvwinch(levelWindow, 1, 7);

	if (lever3Loc != 100663404 && !lever3Pulled) {
		pullLever3();
		lever3Pulled = true;

	}

}

void Level1::reDrawEntities() {

	updateCannons();

	updateZmije();

	updateDemons();

	updateBullets();


	wrefresh(levelWindow);
	updateMemoryLeakInfoBox();
}

void Level1::updateCannons() {


	if (count != ciklusStvaranjaMetkovaTop) {
		count++;
		return;
	}
	count = 0;

	for (Top& t : listaTopova) {

		std::uniform_int_distribution<int> dist(0, 999);
		int rr = dist(rng);

		if (rr > 300) {
			continue;
		}
		int tempX = t.curLocX;
		int tempY = t.curLocY;



		listaMetkova.emplace_back(new Bullet(tempY, tempX, t.facingDirection));
	}

}

void Level1::drawStones() {


	mvwaddch(levelWindow, 21, 60, cLookStena);
	mvwaddch(levelWindow, 21, 58, cLookStena);


	mvwaddch(levelWindow, 23, 8, cLookStena);
	mvwaddch(levelWindow, 24, 2, cLookStena);
	mvwaddch(levelWindow, 24, 20, cLookStena);
	mvwaddch(levelWindow, 22, 30, cLookStena);
	mvwaddch(levelWindow, 22, 31, cLookStena);
	mvwaddch(levelWindow, 23, 30, cLookStena);
	mvwaddch(levelWindow, 21, 33, cLookStena);
	mvwaddch(levelWindow, 23, 33, cLookStena);
	mvwaddch(levelWindow, 22, 35, cLookStena);
	mvwaddch(levelWindow, 22, 36, cLookStena);
	mvwaddch(levelWindow, 22, 37, cLookStena);
	mvwaddch(levelWindow, 22, 38, cLookStena);
	mvwaddch(levelWindow, 24, 35, cLookStena);
	mvwaddch(levelWindow, 24, 49, cLookStena);

	mvwaddch(levelWindow, 22, 67, cLookStena);
	mvwaddch(levelWindow, 23, 67, cLookStena);

	mvwaddch(levelWindow, 22, 72, cLookStena);
	mvwaddch(levelWindow, 23, 72, cLookStena);
	mvwaddch(levelWindow, 23, 73, cLookStena);
}

void Level1::drawCannons()
{
	for (Top& t : listaTopova) {
		mvwaddch(levelWindow, t.curLocY, t.curLocX, t.cLook);


	}
}

void Level1::ispuniListuTopova()
{
	//samo dodas topove ovde, bulleti su reseni sto se tice pravljenja iz topova
	listaTopova.emplace_back(Top(24, 59, 3));
	listaTopova.emplace_back(Top(22, 59, 3));

	listaTopova.emplace_back(Top(20, 76, 2));
	listaTopova.emplace_back(Top(24, 76, 0));




	listaTopova.emplace_back(Top(1, 44, 2));
	listaTopova.emplace_back(Top(1, 45, 2));
	listaTopova.emplace_back(Top(1, 46, 2));
	listaTopova.emplace_back(Top(1, 47, 2));
	listaTopova.emplace_back(Top(1, 48, 2));
	listaTopova.emplace_back(Top(1, 49, 2));
	listaTopova.emplace_back(Top(1, 50, 2));
	listaTopova.emplace_back(Top(1, 51, 2));
	listaTopova.emplace_back(Top(1, 52, 2));
	listaTopova.emplace_back(Top(1, 53, 2));
	listaTopova.emplace_back(Top(1, 54, 2));
	listaTopova.emplace_back(Top(1, 55, 2));
	listaTopova.emplace_back(Top(1, 56, 2));
	listaTopova.emplace_back(Top(1, 57, 2));
	listaTopova.emplace_back(Top(1, 58, 2));
	listaTopova.emplace_back(Top(1, 59, 2));
	listaTopova.emplace_back(Top(1, 60, 2));
	listaTopova.emplace_back(Top(1, 61, 2));
	listaTopova.emplace_back(Top(1, 62, 2));
	listaTopova.emplace_back(Top(1, 63, 2));
	listaTopova.emplace_back(Top(1, 64, 2));
	listaTopova.emplace_back(Top(1, 65, 2));
	listaTopova.emplace_back(Top(1, 66, 2));
	listaTopova.emplace_back(Top(1, 67, 2));
	listaTopova.emplace_back(Top(1, 68, 2));
	listaTopova.emplace_back(Top(1, 69, 2));
	listaTopova.emplace_back(Top(1, 70, 2));
	listaTopova.emplace_back(Top(1, 71, 2));
	listaTopova.emplace_back(Top(1, 72, 2));
	listaTopova.emplace_back(Top(1, 73, 2));
	listaTopova.emplace_back(Top(1, 74, 2));
	listaTopova.emplace_back(Top(1, 75, 2));
	listaTopova.emplace_back(Top(1, 76, 2));
	listaTopova.emplace_back(Top(1, 77, 2));
	listaTopova.emplace_back(Top(1, 78, 2));
	listaTopova.emplace_back(Top(1, 79, 2));
	listaTopova.emplace_back(Top(1, 80, 2));
	listaTopova.emplace_back(Top(1, 81, 2));
	listaTopova.emplace_back(Top(1, 82, 2));
	listaTopova.emplace_back(Top(1, 83, 2));

	listaTopova.emplace_back(Top(20, 69, 2));
	listaTopova.emplace_back(Top(20, 69, 2));
	listaTopova.emplace_back(Top(24, 69, 0));
	listaTopova.emplace_back(Top(24, 69, 0));

	listaTopova.emplace_back(Top(20, 81, 2));
	listaTopova.emplace_back(Top(20, 83, 2));
	listaTopova.emplace_back(Top(21, 80, 1));
	listaTopova.emplace_back(Top(21, 84, 3));
	listaTopova.emplace_back(Top(23, 80, 1));
	listaTopova.emplace_back(Top(23, 84, 3));
	listaTopova.emplace_back(Top(24, 81, 0));
	listaTopova.emplace_back(Top(24, 83, 0));

	listaTopova.emplace_back(Top(21, 115, 3));
	listaTopova.emplace_back(Top(21, 85, 1));

	listaTopova.emplace_back(Top(23, 115, 3));
	listaTopova.emplace_back(Top(23, 85, 1));

	listaTopova.emplace_back(Top(24, 101, 0));
	listaTopova.emplace_back(Top(24, 106, 0));

	listaTopova.emplace_back(Top(7, 16, 1));
	listaTopova.emplace_back(Top(10, 19, 1));
	listaTopova.emplace_back(Top(13, 22, 1));

}

void Level1::removeWallsBoss()
{
	updateBossHp();
	playMusic::playSound("bwaap");

	//lasCheckPointX = p->curLocX;
	//lasCheckPointY = p->curLocY;

	mvwaddch(levelWindow, 1, 34, ' ');
	mvwaddch(levelWindow, 2, 34, ' ');

	mvwaddch(levelWindow, 1, 40, ' ');
	mvwaddch(levelWindow, 2, 40, ' ');

	mvwaddch(levelWindow, 2, 30, ' ');
	mvwaddch(levelWindow, 3, 30, ' ');

	mvwaddch(levelWindow, 2, 22, ' ');
	mvwaddch(levelWindow, 3, 22, ' ');


	mvwaddch(levelWindow, 1, 87, ' ');
	mvwaddch(levelWindow, 2, 87, ' ');
	mvwaddch(levelWindow, 3, 87, ' ');
	mvwaddch(levelWindow, 4, 87, ' ');
	mvwaddch(levelWindow, 5, 87, ' ');
	mvwaddch(levelWindow, 6, 87, ' ');
	mvwaddch(levelWindow, 7, 87, ' ');
	mvwaddch(levelWindow, 8, 87, ' ');
	mvwaddch(levelWindow, 9, 87, ' ');
	mvwaddch(levelWindow, 10, 87, ' ');
	mvwaddch(levelWindow, 11, 87, ' ');
	mvwaddch(levelWindow, 12, 87, ' ');
	mvwaddch(levelWindow, 13, 87, ' ');

	mvwaddch(levelWindow, 13, 88, ' ');
	mvwaddch(levelWindow, 13, 89, ' ');
	mvwaddch(levelWindow, 13, 90, ' ');
	mvwaddch(levelWindow, 13, 91, ' ');
	mvwaddch(levelWindow, 13, 92, ' ');
	mvwaddch(levelWindow, 13, 93, ' ');
	mvwaddch(levelWindow, 13, 94, ' ');
	mvwaddch(levelWindow, 13, 95, ' ');
	mvwaddch(levelWindow, 13, 96, ' ');
	mvwaddch(levelWindow, 13, 97, ' ');
	mvwaddch(levelWindow, 13, 98, ' ');
	mvwaddch(levelWindow, 13, 99, ' ');
	mvwaddch(levelWindow, 13, 100, ' ');
	mvwaddch(levelWindow, 13, 101, ' ');
	mvwaddch(levelWindow, 13, 102, ' ');
	mvwaddch(levelWindow, 13, 103, ' ');
	mvwaddch(levelWindow, 13, 104, ' ');
	mvwaddch(levelWindow, 13, 105, ' ');
	mvwaddch(levelWindow, 13, 106, ' ');
	mvwaddch(levelWindow, 13, 107, ' ');
	mvwaddch(levelWindow, 13, 108, ' ');
	mvwaddch(levelWindow, 13, 109, ' ');
	mvwaddch(levelWindow, 13, 110, ' ');
	mvwaddch(levelWindow, 13, 111, ' ');
	mvwaddch(levelWindow, 13, 112, ' ');
	mvwaddch(levelWindow, 13, 113, ' ');
	mvwaddch(levelWindow, 13, 114, ' ');
	mvwaddch(levelWindow, 13, 115, ' ');

	listaDemona.emplace_back(new Demon(13, 50));
	listaDemona.emplace_back(new Demon(14, 53));
	listaDemona.emplace_back(new Demon(15, 45));
	listaDemona.emplace_back(new Demon(16, 43));
	listaDemona.emplace_back(new Demon(17, 52));


	listaZmija.emplace_back(new Snejk(17, 84, 0));
	listaZmija.emplace_back(new Snejk(14, 85, 0));
	listaZmija.emplace_back(new Snejk(13, 86, 2));

	wattron(levelWindow, COLOR_PAIR(8));
	mvwprintw(levelWindow, 15, 60, "A");
	mvwprintw(levelWindow, 17, 62, "A");
	mvwprintw(levelWindow, 19, 63, "A");
	mvwprintw(levelWindow, 14, 53, "A");
	mvwprintw(levelWindow, 15, 50, "A");

	wattroff(levelWindow, COLOR_PAIR(8));


}

void Level1::ispuniListuZmija() {

	listaZmija.emplace_back(new Snejk(2, 1, 1));
	listaZmija.emplace_back(new Snejk(4, 1, 1));
	listaZmija.emplace_back(new Snejk(6, 1, 1));

	listaZmija.emplace_back(new Snejk(3, 14, 3));
	listaZmija.emplace_back(new Snejk(5, 14, 3));

	listaZmija.emplace_back(new Snejk(10, 10, 2));
	listaZmija.emplace_back(new Snejk(10, 11, 2));
	listaZmija.emplace_back(new Snejk(10, 12, 2));
	listaZmija.emplace_back(new Snejk(10, 9, 2));
	listaZmija.emplace_back(new Snejk(10, 8, 2));
	listaZmija.emplace_back(new Snejk(10, 7, 2));



}

void Level1::ispuniListuDemona()
{
	listaDemona.emplace_back(new Demon(15, 90));
	listaDemona.emplace_back(new Demon(15, 90));
	listaDemona.emplace_back(new Demon(15, 90));
	listaDemona.emplace_back(new Demon(15, 90));
	listaDemona.emplace_back(new Demon(17, 100));
	listaDemona.emplace_back(new Demon(17, 100));
	listaDemona.emplace_back(new Demon(17, 100));
	listaDemona.emplace_back(new Demon(17, 100));
	listaDemona.emplace_back(new Demon(17, 100));
	listaDemona.emplace_back(new Demon(18, 108));
	listaDemona.emplace_back(new Demon(18, 108));
	listaDemona.emplace_back(new Demon(18, 108));
	listaDemona.emplace_back(new Demon(18, 108));
	listaDemona.emplace_back(new Demon(14, 113));
	listaDemona.emplace_back(new Demon(14, 113));
	listaDemona.emplace_back(new Demon(14, 113));
	listaDemona.emplace_back(new Demon(14, 113));
	listaDemona.emplace_back(new Demon(9, 3));

	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));
	listaDemona.emplace_back(new Demon(2, 27));


	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));
	listaDemona.emplace_back(new Demon(2, 29));


}

void Level1::updateDemons()
{

	for (auto it = listaDemona.begin(); it != listaDemona.end(); /* no increment here */) {
		Demon* d = *it;

		int chNaTrenLok = mvwinch(levelWindow, d->curLocY, d->curLocX);


		if (d->curLocY == p->curLocY && d->curLocX == p->curLocX) {
			playMusic::playSound("plazerDeath");

			p->health--;
			flash();
			Sleep(50);
			flash();
			Sleep(50);
			flash();


			mvwaddch(levelWindow, p->curLocY, p->curLocX, ' ');
			mvwaddch(levelWindow, lasCheckPointY, lasCheckPointX, p->cLook);
			p->curLocX = lasCheckPointX;
			p->curLocY = lasCheckPointY;

			updateLivesLeft();

		}
		else {
			mvwaddch(levelWindow, d->curLocY, d->curLocX, ' ');
		}
		//134217770 == bullet
		if (chNaTrenLok == 134217770) {


			for (auto bl = listaMetkova.begin(); bl != listaMetkova.end(); /* no increment here */) {
				Bullet* b = *bl;

				if (d->curLocX == b->locX && b->locY == d->curLocY) {
					mvwaddch(levelWindow, b->locY, b->locX, ' ');
					delete b;
					bl = listaMetkova.erase(bl);
					continue;
				}
				++bl;
			}

			delete d;
			it = listaDemona.erase(it);
			playMusic::playSound("npcDeath");



			continue;
		}




		std::uniform_int_distribution<int> dist(0, 999);
		int rr = dist(rng);

		if (rr > 750) {
			d->curLocX++;
		}
		else if (rr > 500) {
			d->curLocX--;
		}
		else if (rr > 250) {
			d->curLocY++;
		}
		else {
			d->curLocY--;
		}






		int chNaLok = mvwinch(levelWindow, d->curLocY, d->curLocX);

		//32 == Space
		if (chNaLok != 32) {

			//ako demon udari mene skini mi helte, flesuj ekran, postavi me na mesto poslednjeg checkpointa, ovo su moja 4 stanja karaktera
			if (chNaLok == 100663376 || chNaLok == 101711952 || chNaLok == 100925520 || chNaLok == 100794448) {
				playMusic::playSound("plazerDeath");
				p->health--;
				flash();
				Sleep(50);
				flash();
				Sleep(50);
				flash();


				mvwaddch(levelWindow, p->curLocY, p->curLocX, ' ');
				mvwaddch(levelWindow, lasCheckPointY, lasCheckPointX, p->cLook);
				p->curLocX = lasCheckPointX;
				p->curLocY = lasCheckPointY;

				updateLivesLeft();
			}//134217770 == bullet
			else if (chNaLok == 134217770) {


				for (auto bl = listaMetkova.begin(); bl != listaMetkova.end(); /* no increment here */) {
					Bullet* b = *bl;

					if (d->curLocX == b->locX && b->locY == d->curLocY) {
						mvwaddch(levelWindow, b->locY, b->locX, ' ');
						delete b;
						bl = listaMetkova.erase(bl);
						continue;
					}
					++bl;
				}

				delete d;
				it = listaDemona.erase(it);
				playMusic::playSound("npcDeath");




				continue;
			}
			else {

				if (rr > 750) {
					d->curLocX--;
				}
				else if (rr > 500) {
					d->curLocX++;
				}
				else if (rr > 250) {
					d->curLocY--;
				}
				else {
					d->curLocY++;

				}

				++it;

			}





		}
		else {
			++it;
		}

		mvwaddch(levelWindow, d->curLocY, d->curLocX, d->cLook);


	}
}



void Level1::updateZmije() {


	for (auto it = listaZmija.begin(); it != listaZmija.end(); /* no increment here */) {
		Snejk* s = *it;

		int chNaTrenLok = mvwinch(levelWindow, s->curLocY, s->curLocX);


		if (s->curLocY == p->curLocY && s->curLocX == p->curLocX) {
			playMusic::playSound("plazerDeath");
			p->health--;
			flash();
			Sleep(50);
			flash();
			Sleep(50);
			flash();


			mvwaddch(levelWindow, p->curLocY, p->curLocX, ' ');
			mvwaddch(levelWindow, lasCheckPointY, lasCheckPointX, p->cLook);
			p->curLocX = lasCheckPointX;
			p->curLocY = lasCheckPointY;

			updateLivesLeft();

		}
		else {
			mvwaddch(levelWindow, s->curLocY, s->curLocX, ' ');
		}
		//134217770 == bullet
		if (chNaTrenLok == 134217770) {


			for (auto bl = listaMetkova.begin(); bl != listaMetkova.end(); /* no increment here */) {
				Bullet* b = *bl;

				if (s->curLocX == b->locX && b->locY == s->curLocY) {
					mvwaddch(levelWindow, b->locY, b->locX, ' ');
					delete b;
					bl = listaMetkova.erase(bl);
					continue;
				}
				++bl;
			}

			delete s;
			it = listaZmija.erase(it);
			playMusic::playSound("npcDeath");



			continue;
		}
		switch (s->facingDirection) {
		case 0:
			s->curLocY--;
			break;
		case 1:
			s->curLocX++;
			break;
		case 2:
			s->curLocY++;
			break;
		case 3:
			s->curLocX--;
			break;
		default:
			break;
		}

		int chNaLok = mvwinch(levelWindow, s->curLocY, s->curLocX);

		//32 == Space
		if (chNaLok != 32) {

			//ako zmija udari mene skini mi helte, flesuj ekran, postavi me na mesto poslednjeg checkpointa, ovo su moja 4 stanja karaktera
			if (chNaLok == 100663376 || chNaLok == 101711952 || chNaLok == 100925520 || chNaLok == 100794448) {
				playMusic::playSound("plazerDeath");
				p->health--;
				flash();
				Sleep(50);
				flash();
				Sleep(50);
				flash();


				mvwaddch(levelWindow, p->curLocY, p->curLocX, ' ');
				mvwaddch(levelWindow, lasCheckPointY, lasCheckPointX, p->cLook);
				p->curLocX = lasCheckPointX;
				p->curLocY = lasCheckPointY;

				updateLivesLeft();
			}//134217770 == bullet
			else if (chNaLok == 134217770) {


				for (auto bl = listaMetkova.begin(); bl != listaMetkova.end(); /* no increment here */) {
					Bullet* b = *bl;

					if (s->curLocX == b->locX && b->locY == s->curLocY) {
						mvwaddch(levelWindow, b->locY, b->locX, ' ');
						delete b;
						bl = listaMetkova.erase(bl);
						continue;
					}
					++bl;
				}

				delete s;
				it = listaZmija.erase(it);
				playMusic::playSound("npcDeath");



				continue;
			}
			else {

				switch (s->facingDirection) {
				case 0:
					s->facingDirection = 2;
					s->curLocY++;
					s->curLocY++;
					break;
				case 1:
					s->facingDirection = 3;
					s->curLocX--;
					s->curLocX--;
					break;
				case 2:
					s->facingDirection = 0;
					s->curLocY--;
					s->curLocY--;
					break;
				case 3:
					s->facingDirection = 1;
					s->curLocX++;
					s->curLocX++;
					break;
				default:
					break;
				}

				++it;

			}





		}
		else {
			++it;
		}

		mvwaddch(levelWindow, s->curLocY, s->curLocX, s->cLook);


	}
}

void Level1::pullLever1()
{

	mvwaddch(levelWindow, 20, 100, ' ');
	mvwaddch(levelWindow, 20, 101, ' ');
	mvwaddch(levelWindow, 20, 102, ' ');
	mvwaddch(levelWindow, 20, 103, ' ');
	mvwaddch(levelWindow, 20, 104, ' ');
	mvwaddch(levelWindow, 20, 105, ' ');
	mvwaddch(levelWindow, 20, 106, ' ');
	mvwaddch(levelWindow, 20, 107, ' ');

	playMusic::playSound("gateOpen");

}

void Level1::pullLever2()
{
	mvwaddch(levelWindow, 16, 21, ' ');
	mvwaddch(levelWindow, 16, 22, ' ');
	playMusic::playSound("gateOpen");


}

void Level1::pullLever3()
{
	mvwaddch(levelWindow, 2, 35, ' ');
	mvwaddch(levelWindow, 2, 37, ' ');
	mvwaddch(levelWindow, 2, 39, ' ');
	mvwaddch(levelWindow, 3, 36, ' ');
	mvwaddch(levelWindow, 3, 37, ' ');
	mvwaddch(levelWindow, 3, 38, ' ');
	mvwaddch(levelWindow, 4, 37, ' ');
	playMusic::playSound("gateOpen");


}

void Level1::corridorTrap()
{
	playMusic::playSound("booHaha");

	lasCheckPointX = p->curLocX;
	lasCheckPointY = p->curLocY;

	wattron(levelWindow, COLOR_PAIR(8));
	mvwprintw(levelWindow, 17, 33, "A");
	mvwprintw(levelWindow, 17, 34, "A");
	mvwprintw(levelWindow, 17, 40, "A");
	mvwprintw(levelWindow, 17, 41, "A");
	wattroff(levelWindow, COLOR_PAIR(8));

	wattron(levelWindow, COLOR_PAIR(6));
	mvwprintw(levelWindow, 1, 37, "l");
	wattroff(levelWindow, COLOR_PAIR(6));

	listaDemona.emplace_back(new Demon(3, 35));
	listaDemona.emplace_back(new Demon(2, 36));
	listaDemona.emplace_back(new Demon(3, 38));

	listaZmija.emplace_back(new Snejk(4, 35, 2));
	listaZmija.emplace_back(new Snejk(4, 36, 2));
	listaZmija.emplace_back(new Snejk(4, 37, 0));
	listaZmija.emplace_back(new Snejk(4, 38, 2));
	listaZmija.emplace_back(new Snejk(4, 39, 2));



	mvwaddch(levelWindow, 1, 34, '#');
	mvwaddch(levelWindow, 2, 34, '#');
	mvwaddch(levelWindow, 1, 40, '#');
	mvwaddch(levelWindow, 2, 40, '#');

	wrefresh(levelWindow);


}


void Level1::updateBullets()
{
	for (auto it = listaMetkova.begin(); it != listaMetkova.end(); /* no increment here */) {
		Bullet* b = *it;

		if (b->locY == p->curLocY && b->locX == p->curLocX) {
			//ne treba nista da radi jer je na mom mestu
		}
		else if (mvwinch(levelWindow, b->locY, b->locX) == 201326680) {

			mvwaddch(levelWindow, b->locY, b->locX, 'X' | COLOR_PAIR(12));
		}
		else {
			mvwaddch(levelWindow, b->locY, b->locX, ' ');
		}


		switch (b->facingDirection) {
		case 0:
			b->locY--;
			break;
		case 1:
			b->locX++;
			break;
		case 2:
			b->locY++;
			break;
		case 3:
			b->locX--;
			break;
		default:
			break;
		}

		int chNaLok = mvwinch(levelWindow, b->locY, b->locX);

		//32 == Space , 167772243 = snake, 134217770  = metak

		//sto se tice snejk, ovako sam napravio da posle proveri zmija da li stoji na metku, ovo je dobro, ne diraj
		if (!(chNaLok == 32 || chNaLok == 167772243 || chNaLok == 134217770 || chNaLok == 184549444)) {


			//ako metak udari mene skini mi helte, flesuj ekran, postavi me na mesto poslednjeg checkpointa, ovo su moja 4 stanja karaktera
			if (chNaLok == 100663376 || chNaLok == 101711952 || chNaLok == 100925520 || chNaLok == 100794448) {
				p->health--;
				playMusic::playSound("plazerDeath");
				flash();
				Sleep(50);
				flash();
				Sleep(50);
				flash();


				mvwaddch(levelWindow, p->curLocY, p->curLocX, ' ');
				mvwaddch(levelWindow, lasCheckPointY, lasCheckPointX, p->cLook);
				p->curLocX = lasCheckPointX;
				p->curLocY = lasCheckPointY;

				updateLivesLeft();
			}

			if (chNaLok == '/' || chNaLok == '\\' || chNaLok == '-' || chNaLok == '_' || chNaLok == ',' || chNaLok == '|') {
				bossHp--;
				updateBossHp();
				playMusic::playSound("npcDeath");
			}

			//obrisi metak ako nije prazno polje
			delete b;
			it = listaMetkova.erase(it);


		}
		else {

			mvwaddch(levelWindow, b->locY, b->locX, b->cLook);

			++it;
		}


	}
}

void Level1::updateLivesLeft() {

	wattron(playerStatsWindow, COLOR_PAIR(9));
	std::string str = std::to_string(p->health);
	const char* cstr = str.c_str();
	mvwprintw(playerStatsWindow, 4, 33, cstr);
	wattroff(playerStatsWindow, COLOR_PAIR(9));
	wrefresh(playerStatsWindow);

}

void Level1::updateAmmoScreen()
{
	mvwprintw(playerStatsWindow, 4, 13, "    ");
	if (blinkAmmo) {
		wattron(playerStatsWindow, COLOR_PAIR(8));
		std::string str = std::to_string(p->ammo);
		const char* cstr = str.c_str();
		mvwprintw(playerStatsWindow, 4, 13, cstr);
		wattroff(playerStatsWindow, COLOR_PAIR(8));
	}
	else {
		wattron(playerStatsWindow, COLOR_PAIR(14));
		std::string str = std::to_string(p->ammo);
		const char* cstr = str.c_str();
		mvwprintw(playerStatsWindow, 4, 13, cstr);
		wattroff(playerStatsWindow, COLOR_PAIR(14));
	}

	blinkAmmo = !blinkAmmo;

	wrefresh(playerStatsWindow);
}

void Level1::updateBossHp() {

	mvwprintw(levelWindow, 11, 101, " ");
	if (blinkBoss) {
		wattron(levelWindow, COLOR_PAIR(11));
		std::string str = std::to_string(bossHp);
		const char* cstr = str.c_str();
		mvwprintw(levelWindow, 11, 101, cstr);
		wattroff(levelWindow, COLOR_PAIR(11));
	}
	else {
		wattron(levelWindow, COLOR_PAIR(15));
		std::string str = std::to_string(bossHp);
		const char* cstr = str.c_str();
		mvwprintw(levelWindow, 11, 101, cstr);
		wattroff(levelWindow, COLOR_PAIR(15));
	}

	blinkBoss = !blinkBoss;

	wrefresh(playerStatsWindow);
}

void Level1::bossKillScreen()
{
	chtype m = 'm' | COLOR_PAIR(5);

	mvwaddch(levelWindow, 1, 87, m);
	mvwaddch(levelWindow, 2, 87, m);
	mvwaddch(levelWindow, 3, 87, m);
	mvwaddch(levelWindow, 4, 87, m);
	mvwaddch(levelWindow, 5, 87, m);
	mvwaddch(levelWindow, 6, 87, m);
	mvwaddch(levelWindow, 7, 87, m);
	mvwaddch(levelWindow, 8, 87, m);
	mvwaddch(levelWindow, 9, 87, m);
	mvwaddch(levelWindow, 10, 87, m);
	mvwaddch(levelWindow, 11, 87, m);
	mvwaddch(levelWindow, 12, 87, m);
	mvwaddch(levelWindow, 13, 87, m);

	mvwaddch(levelWindow, 13, 88, m);
	mvwaddch(levelWindow, 13, 89, m);
	mvwaddch(levelWindow, 13, 90, m);
	mvwaddch(levelWindow, 13, 91, m);
	mvwaddch(levelWindow, 13, 92, m);
	mvwaddch(levelWindow, 13, 93, m);
	mvwaddch(levelWindow, 13, 94, m);
	mvwaddch(levelWindow, 13, 95, m);
	mvwaddch(levelWindow, 13, 96, m);
	mvwaddch(levelWindow, 13, 97, m);
	mvwaddch(levelWindow, 13, 98, m);
	mvwaddch(levelWindow, 13, 99, m);
	mvwaddch(levelWindow, 13, 100, m);
	mvwaddch(levelWindow, 13, 101, m);
	mvwaddch(levelWindow, 13, 102, m);
	mvwaddch(levelWindow, 13, 103, m);
	mvwaddch(levelWindow, 13, 104, m);
	mvwaddch(levelWindow, 13, 105, m);
	mvwaddch(levelWindow, 13, 106, m);
	mvwaddch(levelWindow, 13, 107, m);
	mvwaddch(levelWindow, 13, 108, m);
	mvwaddch(levelWindow, 13, 109, m);
	mvwaddch(levelWindow, 13, 110, m);
	mvwaddch(levelWindow, 13, 111, m);
	mvwaddch(levelWindow, 13, 112, m);
	mvwaddch(levelWindow, 13, 113, m);
	mvwaddch(levelWindow, 13, 114, m);
	mvwaddch(levelWindow, 13, 115, m);
}


void Level1::updateMemoryLeakInfoBox()
{
	const char* mem = MemoryEater::getMbOfAllocatedMemory();

	mvwaddstr(memoryEaterWindow, 3, 12, "    ");


	if (blink) {

		wattron(memoryEaterWindow, A_STANDOUT);
		mvwaddstr(memoryEaterWindow, 3, 12, mem);
		wattroff(memoryEaterWindow, A_STANDOUT);
		blink = !blink;
	}
	else {
		mvwaddstr(memoryEaterWindow, 3, 12, mem);
		blink = !blink;

	}


	mvwaddstr(memoryEaterWindow, 3, 15, " MB");

	wrefresh(memoryEaterWindow);
}




void Level1::drawLevelWalls()
{
	//########################################     ######################################################################################################################
	wmove(levelWindow, 1, 1); waddstr(levelWindow, "              #     ###########                                                       #                            ");
	wmove(levelWindow, 2, 1); waddstr(levelWindow, "              #      #       #    # # #                                               #,-------------------------, ");
	wmove(levelWindow, 3, 1); waddstr(levelWindow, "              #      #       #   # ### #              ##                              #|  /-------------------\\  | ");
	wmove(levelWindow, 4, 1); waddstr(levelWindow, "              #     ###########  #  #  #                   #               ##         #| | CURENJE U TOKU >:)  | | ");
	wmove(levelWindow, 5, 1); waddstr(levelWindow, "              #      # # # # #   #     #                #       #                 #   #| |      __     __      | | ");
	wmove(levelWindow, 6, 1); waddstr(levelWindow, "              #                  #     #                     ##      #         #      #| |     ( (_____) )     | | ");
	wmove(levelWindow, 7, 1); waddstr(levelWindow, "######  #######                  #     #                 #               #            #| |      [ X  X  ]      | | ");
	wmove(levelWindow, 8, 1); waddstr(levelWindow, "     #        ##                 #     #                                              #| |       \\ ..  /       | | ");
	wmove(levelWindow, 9, 1); waddstr(levelWindow, "     ########  ##                #     #            #            #                    #|  \\_______\\___/________/ |");
	wmove(levelWindow, 10, 1);waddstr(levelWindow, "            ##  ##               #     #                              ##              #|_________________________| ");
	wmove(levelWindow, 11, 1);waddstr(levelWindow, "             ##  ##              #     #    #    #                            # ##    # \\______   [   ]   _______/ ");
	wmove(levelWindow, 12, 1);waddstr(levelWindow, "######        ##  ##             #     #     ## #                 ##                  #       /___________\\       ");
	wmove(levelWindow, 13, 1);waddstr(levelWindow, "     #         ##  ##            #     #                                              #############################");
	wmove(levelWindow, 14, 1);waddstr(levelWindow, "     #   #      ##  ##          ##     ##                                                                          ");
	wmove(levelWindow, 15, 1);waddstr(levelWindow, "     #   #       ##  ##         ##     ##                                           ###                            ");
	wmove(levelWindow, 16, 1);waddstr(levelWindow, "     #   #        ######       ##       ##                                          #               ###############");
	wmove(levelWindow, 17, 1);waddstr(levelWindow, "     #   ##                   ##         ##                             #           #                              ");
	wmove(levelWindow, 18, 1);waddstr(levelWindow, "     #    #########           #############                                         #                              ");
	wmove(levelWindow, 19, 1);waddstr(levelWindow, "     ##            #                                          #  ############################                      ");
	wmove(levelWindow, 20, 1);waddstr(levelWindow, "      ############################# ##############################                         ########################");
	wmove(levelWindow, 21, 1);waddstr(levelWindow, "       #           #        #  #                   ##          ##                                                  ");
	wmove(levelWindow, 22, 1);waddstr(levelWindow, "       #           #                  ##          ##          ##                                                   ");
	wmove(levelWindow, 23, 1);waddstr(levelWindow, "                   #           #       ##        ##                                                                ");
	wmove(levelWindow, 24, 1);waddstr(levelWindow, "       #              #      # #        ##                 ##                                                      ");
	//########################################     ######################################################################################################################




	wrefresh(levelWindow);
}




void Level1::levelLoop() {


	thread inputThread([this]() {

		while (toInput) {
			//choice = -1;
			flushinp();
			Sleep(70);
			if (!toInput) {
				break;
			}
			halfdelay(1);
			choice = wgetch(levelWindow);
			if (!toInput) {
				break;
			}
			switch (choice) {
			case KEY_UP:
				p->moveUp(levelWindow, lasCheckPointY, lasCheckPointX);
				break;
			case KEY_DOWN:
				p->moveDown(levelWindow, lasCheckPointY, lasCheckPointX);
				break;
			case KEY_LEFT:
				p->moveLeft(levelWindow, lasCheckPointY, lasCheckPointX);
				break;
			case KEY_RIGHT:
				p->moveRight(levelWindow, lasCheckPointY, lasCheckPointX);
				break;
			case 'f':
				if (p->ammo > 0) {
					p->ammo--;

					playMusic::playSound("pistolShot");


					listaMetkova.emplace_back(new Bullet(p->curLocY, p->curLocX, p->facingDirection));
				}
				else {
					updateAmmoScreen();
					playMusic::playSound("emptyPistolShot");
				}



				break;
				//27 = ESC
			case 27:
				toInput = false;

				break;
			default:
				break;

			}




		}
		});

	// Detachuj tred tako da radi zasebno
	inputThread.detach();



	while (true) {

		if (bossHp <= 0) {
			bossKillScreen();
			playMusic::playSound("NOO");
			Sleep(5000);
			break;
		}

		if (p->health < 1) {
			toInput = false;
			p->died = true;
			//death screen 
			break;
		}
		else if (won) {
			toInput = false;
			//win screen
			break;
		}       //27 == ESC
		else if (toInput == false) {
			break;
		}


		checkLevers();



		if (p->ammo != previousAmmo) {
			updateAmmoScreen();
		}
		if (p->health != previousHealth) {
			previousHealth = p->health;
			updateLivesLeft();
		}

		previousAmmo = p->ammo;

		this_thread::sleep_for(chrono::milliseconds(tezina));

		reDrawEntities();





	}

	toInput = false;

	clearAllWindows();


}


