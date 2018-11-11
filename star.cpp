#include "header.h"

void Star::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Star::color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
}

void Star::speedUp()
{
	speed = 150 - getLevel() * LEVEL_SPEED;
}

void Star::starUp()
{
	count = 5 + getLevel() * LEVEL_COUNT;
}

int Star::starCount()
{
	return count;
}

void Star::fall()
{
	Star star[MAX_STAR];
	for (int fall = 0; fall < count; fall++)
	{
		if (star[fall].xpos >= 2)
		{
			if (star[fall].wait > 0)
			{
				// ���ð� ���� ���� ���� ����߸��� �ʴ´�.
				star[fall].wait--;
			}
			else
			{
				// ���� ��ĭ �Ʒ��� �̵��Ѵ�.
				star[fall].ypos++;
				// ���� ���ϴܿ� ���� ���� �� ó��.
				if (star[fall].ypos >= 22)
				{
					star[fall].xpos = rand() % 27 + 1;
					star[fall].ypos = 3;
					avoid++;    // ���� ���� ���� ī��Ʈ
					fallenStar += 1; //���� �� ���� ���� ī��Ʈ
				}
				// �� ���
				gotoxy(star[fall].xpos, star[fall].ypos);
				color();
				printf("��");
				collisionCheck(fall, star[fall]);
				if (getRemain() == 0)
				{
					setLevel();
					delete[] star;
					break;
				}
			}
		}
	}
}

void Star::clear()
{
	xpos = rand() % 27 + 1;
	ypos = 3;
	wait = rand() % 20;
}

void Star::collisionCheck(int fall, Star star)
{
	if (abs(star.xpos - this->xpos) < 2 && star.ypos == this->ypos)
	{
		this->gameOver();
		exit(1);
	}
}

void Star::setRemain()
{
	remain = require() - avoid;
}

int Star::getRemain()
{
	return remain;
}