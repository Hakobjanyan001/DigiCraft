#include "tiv.h"

int f(int& a) {
	int arr[a] = {1, 5 ,7, 6, 9 };
	int max_arr = arr[0];
	for(int i = 0; i < a; i++) {
		if(max_arr < arr[i ]) {
			max_arr = arr[i];
		}
	}
	return max_arr;
}
