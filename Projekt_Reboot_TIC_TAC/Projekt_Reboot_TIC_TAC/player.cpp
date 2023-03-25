#include "player.h"

player::player(string name)
{
	this->name = name;
}

string player::get_name()
{
	return name;
}

double player::get_score()
{
	return score;
}

void player::set_score(double score)
{
	this->score = score;
}
