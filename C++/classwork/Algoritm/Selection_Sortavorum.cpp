#include <iostream>
#include <string>
#include <vector>

void swap(int& a, int& b) {
 int tmp = a;
	a = b;
	b = tmp;
}

void selectionSort(std::vector<int>& arr) {
	int size = arr.size();
	for(int i = 0; i < size - 1; i++) {
		int min = i;
		for(int j = i + 1; j < size; j++) {	
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		if( min != i) {
			swap(arr[i], arr[min]);
		}
	}
}


int main() {
	std::vector<int> vec = {7, 2, 4, 3, 5}; // kam std::vector<int> vec = new std::vector<int>() heto vec->push_back();
	selectionSort(vec);
	for( int x : vec ) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}
