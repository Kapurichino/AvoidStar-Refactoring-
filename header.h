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

class Game
{
private:
	int level = 1;
	int xpos = 0;
	int ypos = 0;
	int key = 0;
	int need = 0;
public:
	Game() {};
	~Game() {};
	virtual void gotoxy(int x, int y);
	virtual void color();
	void setPos(int x, int y);
	int getLevel();
	void setLevel();
	void removeCursor();
	void menu();
	void gameOver();
	void loading();
	int require();
};

class Player : public Game
{
private:
	int xpos = 0;
	int ypos = 0;
	int lifePoint = 3;
	int key = 0;
public:
	Player() {};
	~Player() {};
	void gotoxy(int x, int y);
	void move();
	void startLocation();
	void color();
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

class Star : public Game
{
protected:
	int wait;
	int speed;
	int count;
	int avoid = 0;
	int fallenStar = 0;
	int remain = 0;
public:
	Star() {};
	~Star() {};
	void setRemain();
	int getRemain();
	void fall();
	void clear();
	void speedUp();
	void starUp();
	int starCount();
	void gotoxy(int xpos, int ypos);
	void collisionCheck(int fall, Star star);
	void color();
};

class List : public Star
{
public:
	List() {};
	~List() {};
	void state();
	void gotoxy(int x, int y);
};

