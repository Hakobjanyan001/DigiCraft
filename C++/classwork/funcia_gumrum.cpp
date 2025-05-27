#include <iostream>
#include <string>

int sum( int, int, int );

int main() {
		std::cout << "greq dzer arjeqnery\n" << std::endl; 
		int num1;
		int num2;
		int num3;
		std::cin >> num1;
		std::cin >> num2;
		std::cin >> num3;
		std::cout << sum(num1, num2, num3) << std::endl;
return 0;
}


int sum( int iNum1, int iNum2, int iNum3 ) {
	int iSum = 0;
	iSum = iNum1 + iNum2 + iNum3;
	return iSum;
}
