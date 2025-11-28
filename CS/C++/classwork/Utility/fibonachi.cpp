#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	
int fib(int);

int main() {
	std::cout << "greq dzer tivy" << std::endl;
	int x = 0;
	std::cin >> x;
	if ( x > 0) {
	std::cout << fib(x) << std::endl;
	}
	return 0;
}

int fib(int i){
	if( i == 1 || i == 2 ){
	return 1;
	}
	int z = fib(i - 1);
	int c = fib(i - 2); 
	return  z + c ;
}

