#include "header.h"

void List::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void List::color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

void List::state()
{
	color();
	gotoxy(32, 2);
	printf("[��AVOID_STAR��]");
	gotoxy(32, 4); printf("����� ���ؿԴ� ���    :%4d", getFallenStar());
	gotoxy(53, 4); printf("��");
	gotoxy(32, 6); printf("����� �� ���忡�� ����    :%4d", getAvoid());
	gotoxy(58, 6); printf("��");
	gotoxy(32, 8); printf("���������� ����    :%4d",  getRemain());
	gotoxy(48, 8); printf("��");
	gotoxy(32, 10); printf("���� ���� : %d", getLevel());
}