#include "header.h"

int main()
{
	Game play;
	Setting set;

	play.removeCursor();
	play.menu();
	set.setLevel();

	while (1)
	{
		system("cls");
		play.loading();

		set.clear();
		set.require();
		set.starUp();
		set.setRemain();
		set.setSpeed();

		system("cls");
		play.game();
	}
	return 0;
}