#include <iostream>
#include <string>

int main() {
	int a = 5;
	char x[a] = {'H', 'e', 'l', 'l', 'o'};
		for(int i = 0; i < a; i++ ) {
		std::cout << x[i] << std::endl;
		}
	return 0;
}
