#include <iostream>
#include <string>

int sum( int iNum1, int iNum2, int iNum3 ) {
	int iSum = 0;
	iSum = iNum1 + iNum2 + iNum3;
	return iSum;
}

int main() {
		std::cout << "greq dzer arjeqnery\n" << std::endl; 
		int iNum1;
		int iNum2;
		int iNum3;
		std::cin >> iNum1;
		std::cin >> iNum2;
		std::cin >> iNum3;
		std::cout << sum(iNum1, iNum2, iNum3 ) << std::endl;
return 0;
}
