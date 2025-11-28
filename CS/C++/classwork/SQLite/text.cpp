#include <iostream>
#include <sqlite3.h>
#include <stdexcept>

static int callback(void* /*unused*/, int argc, char** argv, char** azColName) {
	for(int i = 0; i < argc; i++) {
		std::cout << azColName[i] << " = "<< (argv[i] ? argv[i] : "NULL" ) << " | ";
	}
	std::cout << "\n";
	return 0;
}

int main() {
	sqlite3* db = nullptr;
	int rc = sqlite3_open("test.db", &db);
	if(rc != SQLITE_OK) {
		std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << "\n";
		sqlite3_close(db);
		return 1;
	}

	const char* sql = 
		"CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);"
		"INSERT INTO person (name, age) VALUES ('Karen', 24), ('Aren', 20);"
		"SELECT id, name, age FROM person;";

	char* errmsg = nullptr;
	rc = sqlite3_exec(db, sql, callback, nullptr, &errmsg);
	if(rc != SQLITE_OK) {
		std::cerr << "SQL error: " << errmsg << "\n";
		sqlite3_free(errmsg);
	}

	sqlite3_close(db);
	return 0;
}
