#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	

void parztver(int);

int main() {
	int x = 0;
	std::cin >> x;
	parztver(x);
	return 0;
}

void parztver( int i) {
	if ( i <= 0 ) {
	std::cout << i << " bacasakan tiv kam 0" << std::endl;
	} else if( i % 2 == 0 || i == 1 ) {
		std::cout << i << " parz tiv che" << std::endl;
		} 
	for (int kes = 2; kes <= i / 2; kes++) {
	  	if ( i % kes == 0) { 
		std::cout << i << " parz tiv che" << std::endl;
		}
		}	
		std::cout << i << " parz tiv e" << std::endl;
}
