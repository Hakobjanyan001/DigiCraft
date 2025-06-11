#include <iostream>
#include <string>


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


/*int main() {
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(int i = 0; i < 10; i++) {
	std::cout << *arr + i << std::endl;
	}
int size = sizeof(arr) / sizeof(arr[0]);
std::cout << size << std::endl;
}
*/
