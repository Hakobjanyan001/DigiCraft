#include <iostream>
#include <sqlite3.h>
#include <../include/sqlutils.h>

static int callback(void* /*unused*/, int argc, char** argv, char** azColName) {
	for(int i = 0; i < argc; i++) {
		std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL" ) << " | ";
	}
	std::cout << "\n";
	return 0;
}

bool create(const std::string& filename, sqlite3*& db) {
	int rc = sqlite3_open(filename.c_str(), &db);
		if(rc != SQLITE_OK) {
		std::cerr << "Can't open DB" << sqlite3_errmsg(db) << "\n";
		sqlite3_close(db);
		return false;
	}
	return true;
}

bool createTable(sqlite3* db) {
	const char* command = "CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
	char* errmsg = nullptr;
	int rc = sqlite3_exec(db, command, callback, nullptr, &errmsg);
	if(rc != SQLITE_OK) {
		std::cerr << "SQL error: " << errmsg << "\n";
		sqlite3_free(errmsg);
		return false;
	}
	return true;
}

bool insert(sqlite3* db, const std::string& name, const int& age) {
	const std::string innerAge = std::to_string(age);
	const std::string command = "INSERT INTO person (name, age) VALUES ('"+ name +"', "+ innerAge + ");";
	char* errmsg = nullptr;
	int rc = sqlite3_exec(db, command.c_str(), callback, nullptr, &errmsg);
	if(rc != SQLITE_OK) {
		std::cerr << "SQL error: " << errmsg << "\n";
		sqlite3_free(errmsg);
		return false;
	}
	return true;
}

bool selectTable(sqlite3* db) {
	const char* command = "SELECT id, name, age FROM person;";
	char* errmsg = nullptr;
	int rc = sqlite3_exec(db, command, callback, nullptr, &errmsg);
	if(rc != SQLITE_OK) {
		std::cerr << "SQL error: " << errmsg << "\n";
		sqlite3_free(errmsg);
		return false;
	}
	return true;
}

void close(sqlite3*& db) {
	sqlite3_close(db);
}
