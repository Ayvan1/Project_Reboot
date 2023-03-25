#pragma once
#include <iostream>
#include <list>
#include "postion.h"

using namespace std;
class play_ground
{
private:
	int x;
	int y;
public:
	void tableau(list<postion>& busy_pos);
	void ground_mark(int player,list<postion> &busy_pos);
};

