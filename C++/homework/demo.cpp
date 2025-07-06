#include <iostream>
#include <string>

void foo(int n){
	for(int i = 0; i <= n; n--){
		std::cout << n << std::endl;
	}
}

int main() {
	foo(7);
	return 0;
}
