#include "postion.h"

postion::postion(int x, int y, int player)
{
	this->x = x;
	this->y = y;
	this->player = player;
}

int postion::get_x()
{
	return x;
}

int postion::get_y()
{
	return y;
}

int postion::get_player()
{
	return player;
}

bool operator==(const postion& c1, const postion& c2)
{
	if ((c1.x == c2.x) && (c1.y == c2.y))
		return true;
	
	return false;
}
int vedri() {
	return 0;
}