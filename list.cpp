#include "header.h"

void List::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void List::state()
{
	gotoxy(32, 2);
	printf("[☆AVOID_STAR☆]");
	gotoxy(32, 4); printf("당신이 피해왔던 모든    :%4d", fallenStar);
	gotoxy(53, 4); printf("★");
	gotoxy(32, 6); printf("당신이 한 라운드에서 피한    :%4d", avoid);
	gotoxy(58, 6); printf("★");
	gotoxy(32, 8); printf("레벨업까지 남은    :%4d",  getRemain());
	gotoxy(48, 8); printf("★");
	gotoxy(32, 10); printf("현재 레벨 : %d", getLevel());
}