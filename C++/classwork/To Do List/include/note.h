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

	bool create(const std::string "my.db"); 
	bool createTable();
	bool insert(const std::string neote, const std::string& during, const std::string& finished);
	bool selectTable();
	void close();
};

class ToDoList : friend sqliteUtilis {

private:
	// Member Data
	std::vector<note> m_note;;
	std::vector<during> m_during;
	std::vector<finished> m_finished;

public:
	// STR/GTR
	ToDoList(const std::string& newNote = "", const std::string& newDuring = "", const std::string& newFinished = "");
	~ToDoList();
	
	void addNote(const std::string& newNote);
	void printAllNotes ();
	void removeNote();

};

#endif // ! _TO_DO_LIST_
