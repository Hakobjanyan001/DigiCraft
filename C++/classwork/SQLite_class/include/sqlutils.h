#ifndef _SQLITE_UTILIS_
#define _SQLITE_UTILIS_
#include <sqlite3.h>

bool create(const std::string& filename, sqlite3*& db); 
bool createTable(sqlite3* db);
bool insert(sqlite3* db, const std::string& name, const int& age);
bool selectTable(sqlite3* db);
void close(sqlite3*& db);

#endif // ! _SQLITE_UTILIS_
