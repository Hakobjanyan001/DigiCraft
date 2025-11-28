#include <iostream>
#include <vector>
#include <../include/a.h>

int main() {
	std::vector<float> numbers = {1, 9.5, 3.4, 7.3};
	std::cout << add(numbers) << std::endl;
	return 0;
}
