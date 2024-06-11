
#include <Windows.h>
#include <locale.h>
#include "InitProgram.h"
#include "playMusic.h"

#define COLOR_GREY 11
InitProgram::InitProgram()
{

	playMusic::keepPlaying = true;
	playMusic::playBackgroundMusics();


	setlocale(LC_ALL, "");
	//namestanje fonta i velicine komandnog prozora
	const wchar_t* fontName = L"Cascadia Mono";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                  // Width of each character in the font
	cfi.dwFontSize.Y = 24;           // Height of the font
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, LF_FACESIZE, fontName);
	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
	setlocale(LC_ALL, "");
	keypad(stdscr, true);

	//pdcurses inicijalizacija ekrana
	initscr();
	//da se ne vidi unos korisnika
	noecho();
	//halfdelay(1);
	cbreak();

	start_color();

	//make terminal fullscreen 
	resize_term(33, 195);Sleep(200);
	keybd_event(VK_F11, 0, 0, 0);keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0);Sleep(100);
	curs_set(0);




	//menu
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);


	//memory
	init_pair(5, COLOR_BLUE, COLOR_BLACK);

	//player
	init_pair(6, COLOR_CYAN, COLOR_BLACK);

	//checkpoint
	init_pair(7, COLOR_BLACK, COLOR_CYAN);

	//municija
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	//municija blink
	init_pair(14, COLOR_BLACK, COLOR_YELLOW);


	//zivot
	init_pair(9, COLOR_RED, COLOR_WHITE);

	//snake
	init_pair(10, COLOR_GREEN, COLOR_WHITE);

	//demon
	init_pair(11, COLOR_RED, COLOR_MAGENTA);

	//top
	init_pair(12, COLOR_RED, COLOR_BLACK);

	//stena
	init_color(COLOR_GREY, 500, 500, 500);
	init_pair(13, COLOR_GREY, COLOR_BLACK);

	//boss
	init_pair(15, COLOR_MAGENTA, COLOR_RED);


}

InitProgram& InitProgram::getInstance()
{


	static InitProgram instance;
	return instance;
}
