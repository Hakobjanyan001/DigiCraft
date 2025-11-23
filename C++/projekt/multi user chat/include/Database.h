#ifndef DATABASE_H
#define DATABASE_H

#include <./User.h>
#include <./Message.h>
#include <string>
#include <vector>
#include <memory>
#include <sqlite3.h>

class Database {
private:
	struct SQLiteDeleter {
		void operator()(sqlite3* ptr) const {
			  if(ptr) {
			  	sqlite3_close(ptr);
			  }
		}
	};

	using SQLitePtr = std::unique_ptr<sqlite3, SQLiteDeleter>;
	
	SQLitePtr db;
	std::string db_name;

	bool execute(const std::string& sql);

public:
	Database(const std::string& filename = "chat.db");
	~Database();
	
	bool open();
	void close() { db.reset(); }
	
	User getUser(const std::string& username);
	int addUser(const std::string& username);
	void addMessage(int user_id, const std::string& content);
	std::vector<Message> getLastMessages(int limit = 50);

};
#endif //DATABASE_H
