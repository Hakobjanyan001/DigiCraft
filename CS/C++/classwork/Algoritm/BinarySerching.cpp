#include <iostream>

bool binarySearch(int arr[], int start, int end, int value) {
        while (start <= end ) {
                int mid = start + ( end - start ) / 2;
                if( arr[mid] == value ) {
                        return true;
                }

                if(arr[mid] < value) {
                        start = mid + 1;
                }else {
                        end = mid - 1;
                }
        }
        return false;
}

int main(){
        int arr[] = {1,2,3,4,5};
        if(binarySearch(arr,0,4,1)){
                std::cout << "true" << std::endl;
        }else {
                std::cout << "false" << std::endl;
        }
}
