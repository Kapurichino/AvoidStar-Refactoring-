#include "header.h"

// ȭ���� Ư�� ��ġ�� �̵��� �ִ� �Լ�.
void Game::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Game::color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

// ���� �Լ�.

void Game::removeCursor(void) // Ŀ���� �Ⱥ��̰��Ѵ�
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void Game::menu(void)
{
	setPos(5, 3);

	gotoxy(xpos, ypos + 0); printf("************************************************"); Sleep(100);
	gotoxy(xpos, ypos + 1); printf("*������������������������*"); Sleep(100);
	gotoxy(xpos, ypos + 2); printf("*�����  ����  �����      ���  �����*"); Sleep(100);
	gotoxy(xpos, ypos + 3); printf("*����                          !   ������*"); Sleep(100);
	gotoxy(xpos, ypos + 4); printf("*������      �����  ��  �����  ����*"); Sleep(100);
	gotoxy(xpos, ypos + 5); printf("*���  ���������������������*"); Sleep(100);
	gotoxy(xpos + 11, ypos + 3); printf(" A V O I D �� S T A R"); Sleep(100);
	gotoxy(xpos, ypos + 6); printf("************************************************"); Sleep(100);
	gotoxy(xpos, ypos + 8); printf("��  �� : Left / Right");
	gotoxy(xpos, ypos + 10); printf("Press Enter Key To Start..");

	for (int cnt = 0;; cnt++) //����ȭ�鿡 ���� �� ��¦�̴� �ִϸ��̼�ȿ�� 
	{
		if (kbhit()) break; //(kbhit�� keyboard hit�� ���Ӹ�����)Ű�Է��� ������ ���ѷ��� ���� 
		if (cnt % 200 == 0) { gotoxy(xpos + 7, ypos + 3); printf("��"); }//cnt�� 200���� ������ �������� ���� ǥ��      
		if ((cnt % 200 - 100) == 0) { gotoxy(xpos + 7, ypos + 3); printf("  "); } //�� ī��Ʈ���� 100ī��Ʈ �������� ���� ���� 
		if ((cnt % 350) == 0) { gotoxy(xpos + 35, ypos + 3); printf("��"); } //������ ������ �ð����� ���� 
		if ((cnt % 350 - 100) == 0) { gotoxy(xpos + 35, ypos + 3); printf("  "); }
		Sleep(10); // 00.1�� ������  
	}

	while (1)
	{
		if (kbhit())
		{
			key = getch();
			if (key == ENTER)
			{
				Sleep(500);
				break;
			}
		}
	}
}

void Game::gameOver()
{
	system("cls");
	setPos(5, 5);

	gotoxy(xpos, ypos + 0); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
	gotoxy(xpos, ypos + 1); printf("��                              ��");
	gotoxy(xpos, ypos + 2); printf("��  +-----------------------+   ��");
	gotoxy(xpos, ypos + 3); printf("��  |  G A M E  O V E R..   |   ��");
	gotoxy(xpos, ypos + 4); printf("��  +-----------------------+   ��");
	gotoxy(xpos, ypos + 5); printf("��       Your Level = %2d        ��", level - 1);
	gotoxy(xpos, ypos + 6); printf("��                              ��");
	gotoxy(xpos, ypos + 7); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
	while (1)
	{
		if (kbhit()) 
		{
			break;
		}
	}
}

void Game::loading()
{
	int x_1, x_2, y_1 = 1, y_2 = 2;
	for (x_1 = 16; x_1 > 0; x_1--)
	{
		gotoxy(x_1, y_1); printf("��");
		y_1++;
	}
	for (x_1 = 1; x_1 < 17; x_1++)
	{
		gotoxy(x_1, y_1); printf("��");
		y_1++;
	}
	for (x_2 = 17; x_2 < 32; x_2++)
	{
		gotoxy(x_2, y_2); printf("��");
		y_2++;
	}
	for (x_2 = 31; x_2 > 16; x_2--)
	{
		gotoxy(x_2, y_2); printf("��");
		y_2++;
	}
	gotoxy(9, 16); printf("[��AVOID_STAR��]");
	gotoxy(14, 18); printf("LEVEL %d", level);
	gotoxy(11, 21); printf("���� �غ���..");
	// �ð� ���� (1�� = 1000)
	Sleep(5000);
}

int Game::getLevel()
{
	return level;
}

void Game::setLevel()
{
	level++;
}

int Game::require()
{
	need = 20 + level * 20;
	return need;
}

void Game::setPos(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
}

