#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	

int add( int, int);
float add( float, float);
double add( double, double);

int main() {
	std::cout << add(7, 8) << std::endl;
	std::cout << add(7.5, 8.2) << std::endl;
	std::cout << add(100.2, 18.9) << std::endl;
return 0;
}

int add(int a, int b) {
	return a + b;
}

float add(float a, float b) {
	return a + b;
}
double add( double a, double b) {
	return a + b;
}
