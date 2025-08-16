#include <iostream>
#include <string>



int main() {
	int age = 0;
	std::cot << "Input your age" << std::endl;
	std::cin >> age;
	if( age <= 0 ) {
		std::cout << "Please input positive age number" << std::endl;
		return 1;
	}
	if( age > 18 ) {
		std::cout << "You are too old" << std::endl;
	} else if( age < 13 ) {
		std::cout << "You are too young" << std::endl
	} else {
		std::cout << "Successful" << std::endl;
	}

	return 0;
}
