#include <iostream>
#include <sqlite3.h>
#include <../include/sqlutils.h>
int main() {
	sqlite3* db = nullptr;
	
	const std::string file = "my.db";
	const std::string name = "Karen";

	create(file, db);
	createTable(db);
	insert(db, name, 21);
	selectTable(db);
	close(db);
	return 0;
}
