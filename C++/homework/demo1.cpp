#include<iostream>
#include<string>

int main() {
	int tox = 0;
	int syun = 0;
	std::cin >> tox;
	std::cin >> syun;
	int** arr = new int*[tox];
	
	for(int i = 0; i < tox; i++) {
		arr[i] = new int[syun];
		for(int j = 0; j < syun; j++) {
			std::cin >> arr[i][j];
		}
	}
		
	for(int i = 0; i < tox; i++) {
		for(int j = 0; j < syun; j++) {
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	for(int i = 0; i < tox; i++) {
		delete [] arr[i] ;
	}
	delete [] arr;
	return 0;
}
