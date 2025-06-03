#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	
int sum(int);

int main() {
		std::cout << "greq 0-ic bardzr tiv: ";
		int a = 0;
		std::cin >> a;
		if (a < 0){
				std::cout << "ynterq drakan tiv" << std::endl;
		} else {
				std::cout << a <<  tvanshanneri gumary` " << sum(a) << std::endl;
		}	
	return 0;
}

int sum(int i){
	if ( i == 0) {
		return 0;
	}
	int x = i % 10;
	int y = i / 10;
	return x + sum(y);
}
