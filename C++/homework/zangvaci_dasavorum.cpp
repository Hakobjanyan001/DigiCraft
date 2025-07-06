#include <iostream>
#include <string>

void fa(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		for(int a = 0; a < size - 1 - i; a++){
			if(arr[a] > arr[a + 1]) {
			int tmp = arr[a];
			arr[a] = arr[a + 1];
			arr[a + 1] = tmp;
			}
		}
	}
	for(int d = 0; d < 5; d++) {
		std::cout << arr[d] << std::endl;
	}
}

int main() {
	int arr[5] = {7,5,0,3,2};
	fa(arr, 5);
	return 0;
}
