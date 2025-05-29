#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	

struct Student {
	std::string Name;
	int Mark;
};

bool isPassed(Student s) {
	return s.Mark >= 51;
}

int main() {
	Student st;
	std::cout << "greq dzer anuny" << std::endl;
	std::cin >> st.Name;
	std::cout << "greq gnahatakany" << std::endl;
	std::cin >> st.Mark;
	if(isPassed(st)) {
		std::cout << st.Name << " passed" << std::endl;
	} else {
		std::cout << st.Name << " failed" << std::endl;
	}
return 0;
}
