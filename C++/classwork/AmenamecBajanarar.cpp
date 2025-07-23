#include <iostream>
#include <string>
int baj(int a, int b) {
	while( b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main() {
	int a = 24, b = 8;
	std::cout << (a * b) / baj(a,b) << std::endl;
	return 0;
} 
