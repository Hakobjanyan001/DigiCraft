#include <iostream>
#include <string>

int main(){
	int arr[8];
       	int max1 = 0;
	int max2 = 0;
	for(int i = 0; i < 8; i++){
		std::cin >> arr[i];
		if(arr[i] >= max2){
			max2 = max1;
			max1 = arr[i];
		}
	}
	std::cout << "amenamec arjeqy: " << max1 <<std::endl;	
	std::cout << "erkrord amenamec arjeqy: " << max2 <<std::endl;
}
