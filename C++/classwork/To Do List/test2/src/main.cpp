#include <iostream>
#include <string>
#include <../include/note.h>

int main(int argc, char** argv) {
	 if(argc < 2) {
		 std::cout << "Usage: " << argv[0] << " <command> [arguments]\n" << std::endl;
		 std::cout << "Commands`\n"<< std::endl;
		 std::cout << " add <task> - Add a new task\n"<< std::endl;
		 std::cout << " list - Show all tasks\n"<< std::endl;
		 std::cout << " find <id> - Find task by ID\n"<< std::endl;
		 std::cout << " remove <id> - Remove tasky by ID\n"<< std::endl;
		 std::cout << " menu - Start\n"<< std::endl;
		 std::cout << "\n"<< std::endl;
		 return 1;
	 }
		 
		 ToDoList note;
		 std::string command = argv[1];

		 if(command == "add" && argc == 3) {
			 std::string task = argv[2];
			 note.addTask(task);
			 std::cout << "Task added\n";
		 }else if(command == "list" && argc == 2) {
			 note.printAllTask();
		 }else if(command == "find" && argc == 3) {
			 int id = std::stoi(argv[2]);
			 note.printIdTask(id);
		 }else if(command == "remove" && argc == 3) {
			 int id = std::stoi(argv[2]);
			 note.removeTask(id);
			 std::cout << "Task" << id << "removed\n";
		 }else {
			 std::cout << "Unknown command or arguments" << std::endl;
			 return 1;
		 }
	return 0;
}
