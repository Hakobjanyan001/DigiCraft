#include <iostream>
#include <string>
#include <../include/utility.h>

void menyu() {
	ToDoList note;
	while(true) {
		int choice;
		std::cout << "[1] Add task: \n"
                	     "[2] Show all notes: \n"
                    	     "[3] Find note: \n"
                 	     "[4] Remove notes: \n"
                    	     "[5] Exit: \n";
		std::cin >> choice;

		int id = 0;
		std::string task;
        	std::cin.ignore();
		switch (choice) {
		   	case 1:
				std::cout << "Write your task" << std::endl;
				std::getline(std::cin, task);
				if(task.empty()) {
					std::cout << "Task cannot be empty \n" << std::endl;
					continue;
				}
				note.addTask(task);
					break;
			case 2:
				note.printAllTask();
					break;
			case 3:
				std::cout << "Write ID for find task" << std::endl;
				std::cin >> id;
				note.printIdTask(id);
				std::cin.ignore();
				break;
			case 4:
				std::cout << "Write ID for remove task" << std::endl;
				std::cin >> id;
				note.removeTask(id);
					break;
       	       		case 5:
				std::cout << "Exiting program" << std::endl;
				return;
			default:
				std::cout << "Unknown input" << std::endl;
				break;

		}
	}
}

