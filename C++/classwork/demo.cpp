#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	
struct Student {
	std::string Name;
	int Mark;
};

bool isPassed(Student s) {
		return s.markd >= 51;
}


int main() {
	Student st;
	std::cout << "grel dzer anuny" << std::endl;
	std::cin >> st.Name;
	std::cout << "grel dzer gnahatakany" << std::endl;
	std::cin >> st.Mark
	if(isPassed(st)) {
	std::cout << st.name << "passed" << std::endl;
	} else {
	std::cout << st.name << "failed" << std::endl;
	}
return 0;
}

