#include <iostream>
#include <string>
int main() {
	int chap = 0 ;
	std::cout << "greq zangvaci chapy" << std::endl;
	std::cin >> chap;
	int* arr = new int[chap];
	float gumar = 0;
	for(int i = 0; i < chap; i++){
		std::cout << "greq " << i << " indeqsi arjeqy" << std::endl;  
		std::cin >> arr[i];
		gumar = gumar + arr[i];
	}
	std::cout << "mijin` " << gumar / chap << std::endl;
}
  
