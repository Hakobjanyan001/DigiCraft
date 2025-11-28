#ifndef DB_WRAPPER_H
#define DB_WRAPPER_H

#include <string>
#include <sqlite3.h>

class DBWrapper {
public:
    DBWrapper(const std::string& db_name);
    ~DBWrapper();

    void initSchema();

    int addCategory(const std::string& name);
    int getCategoryId(const std::string& name);
    int addTodo(const std::string& title, const std::string& category, const std::string& due_date);
    void listTodos(const std::string& filter);
    void markDone(int id);

private:
    sqlite3* db;
};

#endif
