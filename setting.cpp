#include "header.h"

int Setting::need = 0;
int Setting::count = 0;
int Setting::avoid = 0;
int Setting::fallenStar = 0;
int Setting::remain = 0;
int Setting::level = 0;
int Setting::speed = 0;


int Setting::require()
{
	need = 20 + getLevel() * 20;
	return need;
}

void Setting::starUp()
{
	count = 5 + getLevel() * LEVEL_COUNT;
}

int Setting::starCount()
{
	return count;
}

void Setting::setRemain()
{
	remain = require() - avoid;
}

int Setting::getRemain()
{
	return remain;
}

void Setting::setAvoid()
{
	++avoid;
}

int Setting::getAvoid()
{
	return avoid;
}

void Setting::setFallenStar()
{
	++fallenStar;
}

int Setting::getFallenStar()
{
	return fallenStar;
}


int Setting::getLevel()
{
	return level;
}

void Setting::setLevel()
{
	++level;
}

void Setting::clear()
{
	avoid = 0;
}

void Setting::setSpeed()
{
	speed = 150 - getLevel() * LEVEL_SPEED;
}

int Setting::getSpeed()
{
	return speed;
}


