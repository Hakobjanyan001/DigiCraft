#include <iostream>
#include <string>
#include <vector>


void insertionSort(std::vector<int>& arr) {
	int size = arr.size();
	for(int i = 0; i < size - 1; i++) {
		int val = arr[i];
		int j = i -1;
		while( j >= 0 && arr[j] > arr[val]) {
			arr[j - 1] = arr[j];
			j--;
		}
		arr[j + 1] = val;
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
