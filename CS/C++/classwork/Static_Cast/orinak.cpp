#include <iostream>

int main() {
	float a = 4.4;
	int d = a;
	std::cout << d << std::endl << std::endl;

	double b = 3.3;
	int f = b;
        std::cout << b << std::endl << std::endl;

	int c = 4;
	double g = c;
	std::cout << c << std::endl << std::endl;

	double a = 2.3;
	int b = (int)a;
	std::cout << (int)b << std::endl << std::endl;

	float c = 4.8;
	int d = (int)c;
	std::cout << (int)d << std::endl << std::endl;

	int t = 6;
	float g = (float)g;
	std::cout << (float)g <<std::endl << std::endl;	

	float a = 2.2;
	int b = static_cast<int>(a);
	std::cout << b << std::endl << std::endl;
	
	double c = 2.7;
	int d = static_cast<int>(c);
	std::cout << d << std::endl << std::endl;
	
	int g = 2;
	float t = static_cast<float>(g);
	std::cout << t << std::endl << std::endl;

	const int a = 12;
	std::cout << a << std::endl << std::endl;

	int a = "barev";
	std::cout << a << std::endl;

	return 0;
}

