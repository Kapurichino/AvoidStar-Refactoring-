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
				// 대기시간 동안 아직 별을 떨어뜨리지 않는다.
				star[fall].wait--;
			}
			else
			{
				// 별을 한칸 아래로 이동한다.
				star[fall].ypos++;
				// 별이 최하단에 도착 했을 때 처리.
				if (star[fall].ypos >= 22)
				{
					star[fall].xpos = rand() % 27 + 1;
					star[fall].ypos = 3;
					avoid++;    // 피한 별의 개수 카운트
					fallenStar += 1; //피한 총 별의 개수 카운트
				}
				// 별 출력
				gotoxy(star[fall].xpos, star[fall].ypos);
				color();
				printf("★");
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