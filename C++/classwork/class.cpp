#include <iostream>
#include <string>

/*
int main() {
	int result = 0;
	for(int i = 1; i <= 100; i++ ){
		if(i % 2 != 0) { 
			result = result + i;
		}
	}
		std::cout << result << std::endl;
	return 0;
}


int main() {
	int a,b;
	std::cin >> a >> b;
	int result = a;
	for(int c = 1; c < b; c++) {
		result = result * a;
	}
	std::cout << result << std::endl;
	return 0;
}
*/


int main() {
	int qanak = 0;
	int erkarutyun = 1;
	std::cin >> qanak;
	for(int i = 1; i <= qanak; i++) {
		for(int d = 1; d <= qanak; d++) {
			std::cout << 1;
		}
		std::cout << std::endl;
		erkarutyun = erkarutyun + 2;
	}
		
	return 0;
}
