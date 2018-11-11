#include "header.h"

// 화면의 특정 위치로 이동해 주는 함수.
void Game::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Game::color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

// 게임 함수.

void Game::removeCursor(void) // 커서를 안보이게한다
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
	gotoxy(xpos, ypos + 1); printf("*■□□□■■■□□■■□□■■■■□□■■■□*"); Sleep(100);
	gotoxy(xpos, ypos + 2); printf("*■■■□  ■□□  ■■□□      □□  ■□■■*"); Sleep(100);
	gotoxy(xpos, ypos + 3); printf("*□□□                          !   ■□■■■*"); Sleep(100);
	gotoxy(xpos, ypos + 4); printf("*■■□■■      ■■■■  □  ■□□□  ■□■*"); Sleep(100);
	gotoxy(xpos, ypos + 5); printf("*■■  ■□□□□■■■■□□□■■■□■■□□*"); Sleep(100);
	gotoxy(xpos + 11, ypos + 3); printf(" A V O I D ☆ S T A R"); Sleep(100);
	gotoxy(xpos, ypos + 6); printf("************************************************"); Sleep(100);
	gotoxy(xpos, ypos + 8); printf("◁  ▷ : Left / Right");
	gotoxy(xpos, ypos + 10); printf("Press Enter Key To Start..");

	for (int cnt = 0;; cnt++) //메인화면에 넣은 별 반짝이는 애니메이션효과 
	{
		if (kbhit()) break; //(kbhit은 keyboard hit의 줄임말같다)키입력이 있으면 무한루프 종료 
		if (cnt % 200 == 0) { gotoxy(xpos + 7, ypos + 3); printf("★"); }//cnt가 200으로 나누어 떨어질때 별을 표시      
		if ((cnt % 200 - 100) == 0) { gotoxy(xpos + 7, ypos + 3); printf("  "); } //위 카운트에서 100카운트 간격으로 별을 지움 
		if ((cnt % 350) == 0) { gotoxy(xpos + 35, ypos + 3); printf("☆"); } //윗별과 같지만 시간차를 뒀음 
		if ((cnt % 350 - 100) == 0) { gotoxy(xpos + 35, ypos + 3); printf("  "); }
		Sleep(10); // 00.1초 딜레이  
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

	gotoxy(xpos, ypos + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	gotoxy(xpos, ypos + 1); printf("▤                              ▤");
	gotoxy(xpos, ypos + 2); printf("▤  +-----------------------+   ▤");
	gotoxy(xpos, ypos + 3); printf("▤  |  G A M E  O V E R..   |   ▤");
	gotoxy(xpos, ypos + 4); printf("▤  +-----------------------+   ▤");
	gotoxy(xpos, ypos + 5); printf("▤       Your Level = %2d        ▤", level - 1);
	gotoxy(xpos, ypos + 6); printf("▤                              ▤");
	gotoxy(xpos, ypos + 7); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
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
		gotoxy(x_1, y_1); printf("★");
		y_1++;
	}
	for (x_1 = 1; x_1 < 17; x_1++)
	{
		gotoxy(x_1, y_1); printf("★");
		y_1++;
	}
	for (x_2 = 17; x_2 < 32; x_2++)
	{
		gotoxy(x_2, y_2); printf("★");
		y_2++;
	}
	for (x_2 = 31; x_2 > 16; x_2--)
	{
		gotoxy(x_2, y_2); printf("★");
		y_2++;
	}
	gotoxy(9, 16); printf("[☆AVOID_STAR★]");
	gotoxy(14, 18); printf("LEVEL %d", level);
	gotoxy(11, 21); printf("게임 준비중..");
	// 시간 지연 (1초 = 1000)
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

