#include <curses.h>
#include <Windows.h>
#include <locale.h>

#include "InitProgram.h"

InitProgram::InitProgram()
{
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


	//pdcurses inicijalizacija ekrana
	initscr();
	//da se ne vidi unos korisnika
	noecho();
	halfdelay(2);
	cbreak();
	start_color();

	//make terminal fullscreen 
	resize_term(33, 195);Sleep(200);
	keybd_event(VK_F11, 0, 0, 0);keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0);Sleep(100);
	curs_set(0);

}

InitProgram& InitProgram::getInstance()
{


	static InitProgram instance;
	return instance;
}
