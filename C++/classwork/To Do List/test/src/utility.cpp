#include <iostream>
#include <string>
#include <../include/utility.h>

void menyu() {
	ToDoList note;
	while(true) {
		int choice;
		std::cout << "[1] Add task: "
                	     "[2] Show all notes: "
                    	     "[3] Find note: "
                 	     "[4] Remove all notes: "
                    	     "[5] Exit: ";
		std::cin >> choice;
				int id = 0;
				std::string task;
        
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
				std::cout << "????" << std::endl;
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

