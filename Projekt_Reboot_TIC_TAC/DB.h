#pragma once
#include "sqlite3.h"
#include <string>
#include <iostream>
#include "player.h"
using namespace std;
class DB
{
private:
	char* err;
	sqlite3* db;
	int record;
	sqlite3_stmt* stmt;
public:
	DB();
	void read();
	void create(player);
	void update(player player, string condition);
	void delet(string);
	void close();
};

