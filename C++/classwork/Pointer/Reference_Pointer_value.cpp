#include <iostream>
#include <string>

//pass by

void funkcia(int num){
num += 1;
std::cout << num << std::endl;
}


void funkcia(int& num){
num += 1;
std::cout << num << std::endl;
}

void funkcia(int* num){
*num += 1;
std::cout << *num << std::endl;
}

// Return________________________________________________________

int funkcia(const int a) { //Return Value
a += 1;
return a;
}

int main() {
int num = funkcia(&num);
	return 0;
}


//_______________________________________________________


int* funkcia( int a) { // Return Pointer
a += a;
return &a;
}

int main() {
int& num  = funkcia(&num);
	return 0;
}

//______________________________________________________



int& funkcia(int a) { // Return Reference
a += 1;
return a;
}

int main() {
funkcia(num);
	return 0;
}

//____________________________________________________________

const int& funkcia(const int& a) {
    return a;
}

int main() {
    int num = 5;
    const int& result = funkcia(num);  // 
    std::cout << result << std::endl;
    return 0;
}


//__________________________________________________________

int& funkcia(int& a) {
    return a;
}

int main() {
    int num = 5;
    int& result = funkcia(num);
    result = 10;
    std::cout << num << std::endl;  // 
    return 0;
}
