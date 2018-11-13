#include "header.h"

void Map::color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), SKYBLUE);
}

void Map::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Map::generate()
{
	this->color();
	for (int block = 1; block <= MAP_XSIZE; block++)
	{
		gotoxy(block, MAP_YSIZE); printf("¢Ë");
		block++;
	}
}