#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	

int num( int );

int main() {
	num(15);
return 0;
}

int num( int i ){
	if( i < 1 ){	
	return 0;
	}else {
	std::cout << i << std::endl;
	i--;
	return num(i);
	}	
}
