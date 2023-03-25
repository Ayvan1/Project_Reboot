#pragma once
class postion
{
private:
	int x, y, player;
public:
	postion(int, int,int);
	int get_x();
	int get_y();
	int get_player();
	friend bool operator==(const postion&,const postion&);
};