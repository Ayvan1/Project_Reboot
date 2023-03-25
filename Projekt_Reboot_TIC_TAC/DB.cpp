#include "DB.h"

DB::DB()
{
	char sql_command[] = "IF NOT EXISTS CREATE  TABLE SCORE_TABLE (NAME TEXT PRIMARY KEY, SCORE NUMBER NOT NULL);";
	record = sqlite3_open("SCORE", &db);
	if (record) {
		cout << "---> Cannot open database " << sqlite3_errmsg(db) << endl;
		close();
		return;
	}
	else {

		cout << "---> Opened database successfully " << endl;
		int rc = sqlite3_exec(db, sql_command, NULL, NULL, &err);
		if(rc != SQLITE_OK)
			cout << "---> Error " << err;
			
	}
	
}

void DB::read()
{
	sqlite3_prepare_v2(db, "SELECT * FROM SCORE_TABLE",-1,&stmt,0);
	while (sqlite3_step(stmt)) {
		cout << "---> Name | " << sqlite3_column_text(stmt, 0) << " Score | " << sqlite3_column_int(stmt, 1) << endl;
	}
}

void DB::create(player player)
{
	string sql_command = "INSERT INTO SCORE_TABLE VALUES("+ player.get_name() +","+ to_string(player.get_score())+ ")";
	int rc = sqlite3_exec(db, sql_command.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK)
		cout << "---> Creation error" << endl;
}

void DB::update(player player,string condition)
{
	string sql_command = "UPDATE SCORE_TABLE SET SCORE = " + to_string(player.get_score()) + "WHERE " + condition;
	int  rc = sqlite3_exec(db, sql_command.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK)
		cout << "---> Update error" << endl;
}

void DB::delet(string condition)
{
	string sql_command = "DELETE FROM SCORE_TABLE WHERE " + condition;
	int  rc = sqlite3_exec(db, sql_command.c_str(), NULL, NULL, &err);
	if (rc != SQLITE_OK)
		cout << "---> Update error" << endl;
}

void DB::close()
{
	sqlite3_close(db);
}
