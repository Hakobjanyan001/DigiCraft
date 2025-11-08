#include <iostream>
#include <string>

void printArray(int[], const int);

int main() {
	const int erkarutyun = 5;
	int a[erkarutyun] = {1, 78, 45, 95, 63};
	printArray(a, erkarutyun);
	return 0;
}

void printArray(int arr[], const int erkarutyun) {
	for(int i = 0; i < erkarutyun; i++) {
			std::cout << arr[i] << std::endl;
	}
}
