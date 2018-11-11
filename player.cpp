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
	// ��� ������ ó��
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
				if (this->xpos > 1) this->xpos--; break;   // �������� �̵�.
			case RIGHT_MOVE:
				if (this->xpos <= 26) this->xpos++; break; // ���������� �̵�.
			}
		}
		else
		{
			switch (key)
			{
			case ESC:
				system("cls"); //ȭ���� �����.
				gotoxy(6, 6); printf("�÷������ּż� �����մϴ�.");
				puts("\n\n\n\n\n\n");
				Sleep(2000);
				exit(0); //�������� 
			}
		}
	}
	// ��� ���
	gotoxy(this->xpos, this->ypos);
	color();
	printf("��");
}

