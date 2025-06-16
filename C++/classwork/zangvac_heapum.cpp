#include <iostream>
#include <string>


/*
int main() {
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(int i = 0; i < 10; i++) {
	std::cout << *(arr + i) << std::endl;
	}
int size = sizeof(arr) / sizeof(arr[0]);
std::cout << size << std::endl;
}


int main() {
int arr[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
		};
	for (int i = 0; i < 3; i++) {
		for (int z = 0; z < 3; z++){
			std::cout << ((arr + i) + z) << std::endl;
		}
	}

return 0;
}


*/


/*
int main() {
int* iArr = new int[5];
	for(int z = 0; z < 5; z++) {
		std::cin >> *(iArr + z);
	}

	std::cout << " " << std::endl;

	for(int i = 0; i < 5; i++) {
		std::cout << *(iArr + i) << std::endl;;
	}
delete[] iArr;
 return 0;
}
*/


int main() {
std::cout << "greq tox erkchap zangvaci";
std::cin >> tox;
std::cout << "greq tox erkchap zangvaci";
std::cin >> syun;
int tox = 0;
int syun =0;
	int** iArr = new int* [tox];
	for(int i = 0; i < tox; i++) {
		iArr[i] = new int [syun];
	}
	delite[] iArr;
return 0;
}


