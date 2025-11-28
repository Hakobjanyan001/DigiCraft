#include <iostream>
#include <sqlite3.h>
#include <../include/math.h>

void test_add() {

	if(add(7, 8 == 15 & sub(7, 8) == -1)) {
		std::cout << "Test 1 passed "  << std::endl;
	} else {
	std::cout << "Test 1 failid" << std::endl;
	}
	
	if(add(17, 3 == 20 & sub(17, 7) == 10)) {
		std::cout << "Test 2 passed " << std::endl;
	} else {
	std::cout << "Test 2 failid" << std::endl;
	}

	if(add(7, 9 == 16 & sub(6, 1) == 5)) {
		std::cout << "Test 3 passed " << std::endl;
	} else {
	std::cout << "Test 3 failid" << std::endl;
	}


	if(add(1, 0 == 1 & sub(1, 1) == 0)) {
		std::cout << "Test 4 passed " << std::endl;
	} else {
	std::cout << "Test 4 failid" << std::endl;
	}

}

int main() {
	test_add();
	return 0;
}
