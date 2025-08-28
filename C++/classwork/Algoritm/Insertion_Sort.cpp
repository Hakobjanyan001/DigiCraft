#include <iostream>
#include <string>
#include <vector>

void swap(int& a, int& b) {
 int tmp = a;
	a = b;
	b = tmp;
}

void insertionSort(std::vector<int>& arr) {
	bool swapped = false;
	int size = arr.size();
	for(int i = 0; i < size - 1; i++) {

	}
}


int main() {
	std::vector<int> vec = {12, 9, 15, 4, 2}; // kam std::vector<int> vec = new std::vector<int>() heto vec->push_back();
	insertionSort(vec);
	for( int x : vec ) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}
