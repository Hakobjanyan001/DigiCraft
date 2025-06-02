#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	

int factoryal( int );

int main() {
	std::cout << "greq tivy" << std::endl;
	int x = 0;
	std::cin >> x;
	if ( x >= 0) {
	factoryal(x);
	int iPatasxan = factoryal(x);
	std::cout << iPatasxan << std::endl;
	}
return 0;
}

int factoryal( int i ){
	if( i == 0 || i == 1 ) {
		return 1;
	}
	int patasxan = i * factoryal( i - 1 );
	return patasxan;
}
