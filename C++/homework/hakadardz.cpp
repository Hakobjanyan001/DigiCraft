#include <iostream>
#include <string>

int fa(int n){
	int hakadardz = 0;
	while(n != 0) {
		int verjinTiv = n % 10;
		hakadardz = hakadardz * 10 + verjinTiv;
		n = n / 10;
	}
	return hakadardz;
}

int main() {
	std::cout << fa(123) << std::endl;
	return 0;
}
