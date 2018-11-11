#include "header.h"

int main()
{
	Game play;
	List list;
	Player player;
	Map map;

	play.removeCursor();
	play.menu();
	system("cls");

	while (1)
	{
		play.loading();
		system("cls");
		player.startLocation();
		while (1) 
		{
			map.generate();
			player.move();
		}
	}
	return 0;
}