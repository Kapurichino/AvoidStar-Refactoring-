#include <iostream>
#include <windows.h> 
#include <conio.h> 

// ���� ȯ�� ����

#define MAX_STAR 80 // ���� �ִ� ����.
#define LEVEL_COUNT 3   // �������� �þ ���� ����
#define LEVEL_SPEED 10  // �������� ������ ���ǵ� (1000 = 1��, 15 = 0.015��)

#define ENTER 13 // ����
#define ESC 27 // �������� 
#define LEFT_MOVE 75
#define RIGHT_MOVE 77

#define MAP_XSIZE 28
#define MAP_YSIZE 22

#define RED 4 // �÷��̾��� ����
#define YELLOW 6 // ���� ����
#define SKYBLUE 11 // ��� ����
#define WHITE 15 // ���� ����

class Setting
{
private:
	static int need;
	static int count;
	static int avoid;
	static int fallenStar;
	static int remain;
	static int level;
	static int speed;
public:
	int require();
	void setAvoid();
	int getAvoid();
	void setFallenStar();
	int getFallenStar();
	void setRemain();
	int getRemain();
	void starUp();
	int starCount();
	int getLevel();
	void setLevel();
	void clear();
	void setSpeed();
	int getSpeed();
};

class Game : public Setting
{
private:
	int xpos = 0;
	int ypos = 0;
	int key = 0;
public:
	Game() {};
	~Game() {};
	virtual void gotoxy(int x, int y);
	virtual void color();
	void setPos(int x, int y);
	void removeCursor();
	void menu();
	void gameOver();
	void loading();
	int game();
};

class Star : public Game
{
public:
	int xpos;
	int ypos;
	int wait;
	Star() {};
	~Star() {};
	void gotoxy(int xpos, int ypos);
	void color();
	void clear();
};

class Player : public Game
{
private:
	int xpos = 0;
	int ypos = 0;
	int key = 0;
public:
	Player() {};
	~Player() {};
	void gotoxy(int x, int y);
	void move();
	void startLocation();
	void color();
	void collisionCheck(Star star);
};

class Map
{
private:
	int blockCount = 0;
	int xpos = 5;
	int ypos = 3;
public:
	Map() {};
	~Map() {};
	void generate();
	void gotoxy(int x, int y);
	void color();
};

class List : public Game
{
public:
	List() {};
	~List() {};
	void state();
	void gotoxy(int x, int y);
	void color();
};

