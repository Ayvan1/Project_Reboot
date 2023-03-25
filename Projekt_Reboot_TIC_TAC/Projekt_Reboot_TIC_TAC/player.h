#pragma once
#include <iostream>
#include <string>

using namespace std;

class player
{
private:
	string name;
	double score;
public:
	player(string);
	string get_name();
	double get_score();
	void set_score(double score);
};

