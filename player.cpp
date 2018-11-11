#include "header.h"

void Player::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Player::color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
}

void Player::startLocation()
{
	this->xpos = 14;
	this->ypos = 21;
}

void Player::move()
{
	// 사람 움직임 처리
	while (kbhit())
	{
		key = getch();
		if (key == 224)
		{
			do
			{
				key = getch();
			} while (key == 224);
			switch (key)
			{
			case LEFT_MOVE:
				if (this->xpos > 1) this->xpos--; break;   // 왼쪽으로 이동.
			case RIGHT_MOVE:
				if (this->xpos <= 26) this->xpos++; break; // 오른쪽으로 이동.
			}
		}
		else
		{
			switch (key)
			{
			case ESC:
				system("cls"); //화면을 지운다.
				gotoxy(6, 6); printf("플레이해주셔서 감사합니다.");
				puts("\n\n\n\n\n\n");
				Sleep(2000);
				exit(0); //게임종료 
			}
		}
	}
	// 사람 출력
	gotoxy(this->xpos, this->ypos);
	color();
	printf("♥");
}

