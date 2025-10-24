#include "../include/db_wrapper.h"
#include <iostream>

int main(int argc, char** argv) {
    DBWrapper db("my.db");
    db.initSchema();

    if (argc < 2) {
	    std::cout << "Usage:\n";
	    std::cout << "  ./todo addcat <name>\n";
	    std::cout << "  ./todo addtodo <title> <category> <YYYY-MM-DD>\n";
	    std::cout << "  ./todo list [--all|--pending|--category=<cat>]\n";
	    std::cout << "  ./todo complete <id>\n";
        return 1;
    }

    std::string cmd = argv[1];

    if (cmd == "addcat" && argc == 3) {
        std::string name = argv[2];
        if (db.addCategory(name) != -1)
            std::cout << "Category '" << name << "' added\n";
        else
            std::cout << "Category already exists\n";
    }
    else if (cmd == "addtodo" && argc == 5) {
        std::string title = argv[2];
        std::string cat = argv[3];
        std::string date = argv[4];
        int id = db.addTodo(title, cat, date);
        if (id != -1)
            std::cout << "Todo " << id << " added\n";
    }
    else if (cmd == "list") {
        std::string filter = (argc == 3) ? argv[2] : "--pending";
        db.listTodos(filter);
    }
    else if (cmd == "complete" && argc == 3) {
        int id = std::stoi(argv[2]);
        db.markDone(id);
    }
    else {
        std::cerr << "Invalid command or arguments.\n";
    }

    return 0;
}
