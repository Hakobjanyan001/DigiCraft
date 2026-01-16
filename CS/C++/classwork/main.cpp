#include <iostream>

void foo() {
	static int a = 0;
	a++;
	std::cout << a << std::endl;
}


int main() {
	
	foo();
	foo();
	foo();
		
return 0;
}
