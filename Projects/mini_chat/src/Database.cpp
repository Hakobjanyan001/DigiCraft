#include <../include/Database.h>
#include <iostream>

Database::Database(const std::string& filename) {
	if(sqlite3_open(filename.c_str(), &db) != SQLITE_OK) {
		std::cerr << "cannot opet DB" << sqlite3_errmsg(db) << std::endl;
	}
}

Database::~Database() {
	sqlite3_close(db);
}

void Database::createTable() {
	const char* command = "CREATE TABLE IF NOT EXISTS messages (id INTEGER PRIMARY KEY, text TEXT);";
	char* errmsg = nullptr;

	int rc = sqlite3_exec(db, command, nullptr, nullptr, &errmsg);

	if(rc != SQLITE_OK) {
		std::cerr << "SQL error" << errmsg << std::endl;
		sqlite3_free(errmsg);
	}
}

void Database::insertMessage(const std::string& message) {
	std::string command = "INSERT INTO messages (text) VALUES ('" + message + "');";
	char* errmsg = nullptr;
	int rc = sqlite3_exec(db, command.c_str(), nullptr, nullptr, &errmsg);
	if(rc != SQLITE_OK) {
		std::cerr << "insert error" << errmsg << std::endl;
		sqlite3_free(errmsg);
	}
}
