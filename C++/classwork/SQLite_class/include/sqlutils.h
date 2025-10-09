#ifndef _SQLITE_UTILIS_
#define _SQLITE_UTILIS_
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
	bool insert(const std::string& name, const int& age);
	bool selectTable();
	void close();
};

#endif // ! _SQLITE_UTILIS_
