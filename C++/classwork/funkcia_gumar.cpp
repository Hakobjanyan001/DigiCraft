#include <iostream>
#include <string>

/*
int sum(int, int, int);

int main() {
	std::cout << "greq dzer arjeqnery\n" << std::endl;
	int iNum1;
	int iNum2;
	int iNum3;
	std::cin >> iNum1;
	std::cin >> iNum2;
	std::cin >> iNum3;
	std::cout << sum(iNum1, iNum2, iNum3) << std::endl;
return 0;
}

int sum( int iGumareli1, int iGumareli2, int iGumareli3){
	int iSum = 0;
	iSum = iGumareli1 + iGumareli2 + iGumareli3;
	return iSum;
}
*/


int sum(int);

int main() {
	std::cout << sum(1) << std::endl;
	return 0;
}

int sum(int i) {
	int iSum = 0;
		for( i = 1; i < 11; i++ ) {
		iSum = iSum + i;	
		}
		return iSum;
}
