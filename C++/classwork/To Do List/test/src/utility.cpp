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
        
		switch (answer) {
		   	case 1:
				std::cout << "Write your task" << std::endl;
				std::string task;
				std::getline(std::cin, task);
				if(task.empty()) {
					std::cout << "Task cannot be empty \n" << std::endl;
					continue;
				}
				note.addNote(task);
					break;
			case 2:
				note.printAllNotes();
					break;
			case 3:
				std::cout << "????" << std::endl;
				break;
			case 4:
				std::cout << "Write ID for remove task" << std::endl;
				int id = 0;
				std::cin >> id;
				note.removeNote(id);
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

