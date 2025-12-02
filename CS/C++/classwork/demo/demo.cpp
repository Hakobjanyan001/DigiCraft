#include <iostream>

int main() {
	int** arr = new int*[3];
	for(int i = 0; i < 3; i++) {
		arr[i] = new int[3];
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			 arr[i][j] = i+1;
		}
	}

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
				std::cout << arr[i][j] << "\n";
		}
	}

	for(int i = 0; i < 0; i++) {
		delete[] arr[i];
	}
	delete[] arr;

return 0;
}
