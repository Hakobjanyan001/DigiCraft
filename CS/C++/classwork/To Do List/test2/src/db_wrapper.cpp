#include "../include/db_wrapper.h"
#include <iostream>

DBWrapper::DBWrapper(const std::string& db_name) {
    if (sqlite3_open(db_name.c_str(), &db)) {
        std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }
}

DBWrapper::~DBWrapper() {
    sqlite3_close(db);
}

void DBWrapper::initSchema() {
    const char* sql_cat =
        "CREATE TABLE IF NOT EXISTS categories ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT UNIQUE);";

    const char* sql_todo =
        "CREATE TABLE IF NOT EXISTS todos ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "title TEXT, "
        "category_id INTEGER, "
        "due_date TEXT, "
        "done INTEGER DEFAULT 0, "
        "FOREIGN KEY(category_id) REFERENCES categories(id));";

    char* err = nullptr;
    if (sqlite3_exec(db, sql_cat, nullptr, nullptr, &err) != SQLITE_OK) {
        std::cerr << "Error creating categories: " << err << std::endl;
        sqlite3_free(err);
    }
    if (sqlite3_exec(db, sql_todo, nullptr, nullptr, &err) != SQLITE_OK) {
        std::cerr << "Error creating todos: " << err << std::endl;
        sqlite3_free(err);
    }
}

int DBWrapper::addCategory(const std::string& name) {
    const char* sql = "INSERT INTO categories(name) VALUES(?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) return -1;

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc == SQLITE_DONE)
        return (int)sqlite3_last_insert_rowid(db);
    return -1;
}

int DBWrapper::getCategoryId(const std::string& name) {
    const char* sql = "SELECT id FROM categories WHERE name=?;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) return -1;

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    int id = -1;
    if (sqlite3_step(stmt) == SQLITE_ROW)
        id = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    return id;
}

int DBWrapper::addTodo(const std::string& title, const std::string& category, const std::string& due_date) {
    sqlite3_exec(db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

    int cat_id = getCategoryId(category);
    if (cat_id == -1) {
        if (addCategory(category) == -1) {
            sqlite3_exec(db, "ROLLBACK;", nullptr, nullptr, nullptr);
            std::cerr << "Error creating category.\n";
            return -1;
        }
        cat_id = getCategoryId(category);
    }

    const char* sql = "INSERT INTO todos(title, category_id, due_date) VALUES(?,?,?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_exec(db, "ROLLBACK;", nullptr, nullptr, nullptr);
        return -1;
    }

    sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, cat_id);
    sqlite3_bind_text(stmt, 3, due_date.c_str(), -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        sqlite3_exec(db, "ROLLBACK;", nullptr, nullptr, nullptr);
        return -1;
    }

    sqlite3_exec(db, "COMMIT;", nullptr, nullptr, nullptr);
    return (int)sqlite3_last_insert_rowid(db);
}

void DBWrapper::listTodos(const std::string& filter) {
    std::string sql =
        "SELECT todos.id, todos.title, categories.name, todos.due_date, todos.done "
        "FROM todos JOIN categories ON todos.category_id = categories.id ";

    if (filter == "--pending")
        sql += "WHERE todos.done = 0 ";
    else if (filter.rfind("--category=", 0) == 0)
        sql += "WHERE categories.name = '" + filter.substr(11) + "' ";

    sql += "ORDER BY todos.id;";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string title = (const char*)sqlite3_column_text(stmt, 1);
        std::string cat = (const char*)sqlite3_column_text(stmt, 2);
        std::string date = (const char*)sqlite3_column_text(stmt, 3);
        int done = sqlite3_column_int(stmt, 4);
        std::cout << id << " | " << title << " | " << cat << " | " << date << " | " 
                  << (done ? "done" : "pending") << "\n";
    }
    sqlite3_finalize(stmt);
}

void DBWrapper::markDone(int id) {
    const char* sql = "UPDATE todos SET done=1 WHERE id=?;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc == SQLITE_DONE)
        std::cout << "Marked " << id << " done\n";
}
