#include <iostream>
#include <sqlite3.h>
#include <../include/sqlutils.h>
#include <vector>

int main() {
	std::vector<std::string> name = {"Karen", "Poxos", "Petros"};
	std::vector<int> age = {24, 27, 17};
	const std::string file = "my.db";
	
	sqliteUtilis sql;
	
	sql.create(file);
	sql.createTable();
	
	for(int i = 0; i < name.size() - 1; i++ ) {
		sql.insert(name[i], age[i]);
	}
	
	sql.selectTable();
	sql.close();
	return 0;
}
