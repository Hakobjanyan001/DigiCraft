#ifndef _TO_DO_LIST_
#define _TO_DO_LIST_
#include <sqlite3.h>
#include <memory>
#include <string>

class sqliteUtilis{
private:
	std::unique_ptr<sqlite3, decltype(&sqlite3_close)> db;
	char* errmsg = nullptr;
	int rc = 0;
	bool chekError(char*& errmsg, int& rc, const char* command);
	static int callback(void* /*unused*/, int argc, char** argv, char** azColName);
public:
	sqliteUtilis();
	~sqliteUtilis();

	bool create(const std::string& filename); 
	bool createTable();
	bool insert(const std::string& task, const std::string& during, const std::string& finished);
	bool selectTable();
	void close();
};

class ToDoList {

private:
	// Member Data
	sqliteUtilis sqlite_db;

public:
	// STR/GTR
	ToDoList();
	~ToDoList();
	
	void addNote(const std::string& newTask);
	void printAllNotes ();
	void removeNote(int& id);

};

#endif // ! _TO_DO_LIST_
