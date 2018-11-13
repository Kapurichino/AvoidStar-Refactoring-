#include "header.h"

void Star::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Star::color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
}




void Star::clear()
{
	xpos = rand() % 27 + 1;
	ypos = 3;
	wait = rand() % 20;
}


