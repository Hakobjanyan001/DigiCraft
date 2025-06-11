#include <iostream>
#include <string>

int* foo(){
	int* a = new int[3];
	a[0] = 4;
	a[1] = 55;
	a[2] = 23;
	return a;
}

int main() {
	int* b = foo();
	std::cout << b << std::endl;
	delete[] b;
	return 0;
}

