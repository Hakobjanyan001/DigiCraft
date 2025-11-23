#include <../include/Database.h>
#include <iostream>
#include <sqlite3.h>

Database::Database(const std::string& filename) : db(nullptr), db_name(filename) {}
Database::~Database() {
		close();
}

bool Database::open() {
	if(db) {
		return true;
	}

	sqlite3* ptr_db = nullptr;
	int rc = sqlite3_open(db_name.c_str(), &ptr_db);
	if(rc != SQLITE_OK) {
		std::cerr << "can't open DB " << sqlite3_errmsg(ptr_db) << "\n";
			sqlite3_close(ptr_db);
			return false;
	}	
	
	db = SQLitePtr(ptr_db);

	const char* creatUser = 
			"CREATE TABLE IF NOT EXISTS users ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"username TEXT UNIQUE NOT NULL);";

	const char* creatMessages = 
			"CREATE TABLE IF NOT EXISTS messages ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"user_id INTEGER, "
			"content TEXT NOT NULL, "
			"timestamp DATETME DEFAULT CURRENT_TIMESTAMP, "
			"FOREIGN KEY(user_id) REFERENCES user(id));";

	if(!execute(creatUser) || !execute(creatMessages)) {
		std::cerr << "db can't creat table\n";
		db.reset();
		return false;
	}
	std::cout << " baza open" << db_name << "\n";
	return true;
}

bool Database::execute(const std::string& command){
	char* errmsg = nullptr;
	int rc = sqlite3_exec(db.get(), command.c_str(), nullptr, nullptr, &errmsg);
	if(rc != SQLITE_OK) {
		std::cerr << "SQL error:" << errmsg << "\n";
		sqlite3_free(errmsg);
		return false;
	}
	return true;
}

User Database::getUser(const std::string& username){
	const char* command = "SELECT id, username FROM users WHERE username = ?;";
	sqlite3_stmt* stmt;

	if(sqlite3_prepare_v2(db.get(), command, -1, &stmt, nullptr) != SQLITE_OK) {
		return User();
	}

	sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

	User u;
	if(sqlite3_step(stmt) == SQLITE_ROW) {
		u.setID(sqlite3_column_int(stmt, 0));
		const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		u.setUsername(name ? name : "");
	} else {
		u.setID(-1);
	}
	sqlite3_finalize(stmt);
	return u;
}

int Database::addUser(const std::string& username) {
	const char* command = "INSERT INTO user (username) VALUES (?);";
	sqlite3_stmt* stmt;

	if(sqlite3_prepare_v2(db.get(), command, -1, &stmt, nullptr) != SQLITE_OK) {
		return -1;
	}
	sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

	if(sqlite3_step(stmt) == SQLITE_DONE) {
		sqlite3_finalize(stmt);
		return static_cast<int>(sqlite3_last_insert_rowid(db.get()));
	}
	
	sqlite3_finalize(stmt);
	return -1;
}

void Database::addMessage(int user_id, const std::string& content) {
	const char* command = "INSERT INTO messages (user_id, content) VALUES (?, ?);";
	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(db.get(), command, -1, &stmt, nullptr);
	sqlite3_bind_int(stmt, 1, user_id);
	sqlite3_bind_text(stmt, 2, content.c_str(), -1, SQLITE_STATIC);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

std::vector<Message> Database::getLastMessages(int limit) {
	std::vector<Message> messages;
	const char* command = 
			"SELECT u.username, m.content, m.timestamp "
			"FROM messages m "
			"JOIN users u ON m.user_id = u.id "
			"ORDER BY m.id DESC LIMIT ?;";

	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db.get(), command, -1, &stmt, nullptr);
	sqlite3_bind_int(stmt, 1, limit);

	while(sqlite3_step(stmt) == SQLITE_ROW) {
		Message m;
		m.username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
		m.connected = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		m.timestamp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
		messages.push_back(m);
	}
	
	sqlite3_finalize(stmt);
	return messages;
}
