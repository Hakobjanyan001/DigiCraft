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


void sum(int);

int main() {
	std::cout << sum(1) << std::endl;
	return 0;
}

void sum(int i) {
	int iSum = 0;
		for( i = 1; i < 11; i++ ) {
		iSum = iSum + i;	
		}
}
*/


void printName( std::string, std::string, int ); 

int main() {
	std::cout << "greq dzer anuny: ";
	std::string sAnun = "";
	std::cin >> sAnun;
	std::cout << "greq dzer azganuny: ";
	std::string sAzganun = "";
	std::cin >> sAzganun;
	std::cout << "greq dzer tariqy: ";
	int iTariq = 0;
	std::cin >> iTariq;
	printName( sAnun, sAzganun, iTariq );	
return 0;
}

void printName ( std::string sName, std::string sSurname, int iAge) {
		std::cout << sName << " " << sSurname << " " << iAge << std::endl;
}



int sumTon ( int n );

int main () {
	std::cout << sumTon(50) << std::endl;
	return 0;
}

int sumTon ( int n ) {
	int iSum = 0;
	for(int i = 1; i <= n; i++) {
	iSum += i;
	}
	return iSum;
}
