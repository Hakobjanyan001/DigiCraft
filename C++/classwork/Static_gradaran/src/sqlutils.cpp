#include <iostream>
#include <sqlite3.h>
#include <../include/sqlutilits.h>

bool create(char* filename, sqlite3*& db) {
	int rc = sqlite3_open(filenamme, &dm);
		if(rc != SQLITE_OK) {
		std::cerr << "Can't open DB" << sqlite3_errmsg(db) << "\n";
		sqlite3_close(db);
		return false;
	}
	return true;
}

bool createTable(sqlite3* db) {
	const char* comand = "CREAT TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
	char* errmsg = nullptr;
	int rc = sqlite3_exec(db, command, callback, nullptr, &errmsg);
	if(rc != SQLITE_OK) {
		str::cerr << "SQL error: " << errmsg << "\n"l;
		sqlite3_ftee(errmsg);
		return false;
	}
	return true;
}

bool insert(sqlite3* db, const std::string& name, const int& age) {
	const std::string innerAge = std::to_string(age);
	const std::string command = "INSERT INTO person (name, age) VALUES ('"+ name"', "+ innerAge + ");";
}

bool selectTable(sqlite3* db) {
	
}

void close(sqlite3* db) {
	sqlite3_close(db);
}
