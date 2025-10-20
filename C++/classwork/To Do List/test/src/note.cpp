#include <iostream>
#include <sqlite3.h>
#include <../include/note.h>

//SQL_CLASS
int sqliteUtilis::callback(void* /*unused*/, int argc, char** argv, char** azColName) {
	for(int i = 0; i < argc; i++) {
		std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL" ) << " | ";
	}
	std::cout << "\n";
	return 0;
}

bool sqliteUtilis::chekError(char*& errmsg, int& rc, const char* command) {
	rc = sqlite3_exec(this->db.get(), command, callback, nullptr, &errmsg);
	if(rc != SQLITE_OK) {
		std::cerr << "SQL error: " << errmsg << "\n";
		sqlite3_free(errmsg);
		return false;
	}
	return true;
}

sqliteUtilis::sqliteUtilis() : db(nullptr, sqlite3_close) {}

sqliteUtilis::~sqliteUtilis() {}

bool sqliteUtilis::create(const std::string& filename) {
	sqlite3* sql_db = nullptr;
	rc = sqlite3_open(filename.c_str(), &sql_db);
		if(rc != SQLITE_OK) {
		std::cerr << "Can't open DB" << sqlite3_errmsg(sql_db) << "\n";
		sqlite3_close(sql_db);
		return false;
	}
	this->db = std::unique_ptr<sqlite3, decltype(&sqlite3_close)>(sql_db, sqlite3_close);
	return true;
}	

bool sqliteUtilis::createTable() {
	const char* command = "CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, note TEXT, during TEXT, finished TEXT);";
	return (chekError(errmsg, rc, command));
}

bool sqliteUtilis::insert(const std::string& note, const std::string& during, const std::string& finished) {
	std::string command = "INSERT INTO tasks (note, during, finished) VALUES ('"+ note +"', '"+ during +"', '"+ finished + "');";
	return (chekError(errmsg, rc, command.c_str()));
}

bool sqliteUtilis::selectTable() {
	const char* command = "SELECT id, note, during, finished FROM tasks;";
	return (chekError(errmsg, rc, command));
}

void sqliteUtilis::close() {
	this->db.reset(); //  unique_ptr kpakvi inqnuruyn
} 


// TO_DO_LIST_CLASS
ToDoList::ToDoList() : sqlite_db() {
	sqlite_db.create("my.db");
	sqlite_db.createTable();
}

ToDoList::~ToDoList() {
}	

void ToDoList::addTask(const std::string& newTask) {
	sqlite_db.insert(newTask, "", "");
}

void ToDoList::printAllTask () {
sqlite_db.selectTable();
}


void ToDoList::removeTask(int id) {
 const char* sql = "DELETE FROM tasks WHERE id = ?;";
}
