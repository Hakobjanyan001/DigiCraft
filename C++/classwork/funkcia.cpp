#include <iostream>
#include <string>

/*
void print(int z) {
	std::cout << z << std::endl;

}

int add(int a, int b) {
	return a + b;
}

int main() {
	int x = add(1, 5);
	int y = add(10, 7);
	print(x);
	print(y);
	return 0;
}
*/


void print(int z) {
	std::cout << z << std::endl;
}

int add(int a, int b) {
	if(a > b) {
	return a - b;
	} else if(a < b) {
		return b - a;
	} else 
		return a = b;

}

int main() {
	int x = add(8, 5);
	int y = add(6, 2);
	int w = add(2, 2);
	print(x);
	print(y);
	print(w);
	return 0;
}

