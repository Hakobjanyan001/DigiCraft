#include <iostream>
#include <string>
#include <vector>

void swap(int& a, int& b) {
 int tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(std::vector<int>& arr) {
	bool swapped = false;
	int size = arr.size();
	for( int i = 0; i < size - 1; i++) {
		for(int j = 0; j < size - 1 - i; j++) {
			if(arr[j] > arr[j] + 1) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if( !swapped ) { break; }
	}
}


int main() {
	std::vector<int> vec = {7, 2, 4, 3, 5}; // kam std::vector<int> vec = new std::vector<int>() heto vec->push_back();
	bubbleSort(vec);
	for( int x : vec ) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}
