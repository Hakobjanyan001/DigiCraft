#include <iostream>
#include <string>

/*int funkcia(const int a) { //Value
return a;
}

int main() {
int num = 5;
int num = funkcia(&num);
	return 0;
}


//_______________________________________________________


int* funkcia(const int a) { //Pointer
return &a;
}

int main() {
int num = 5;
int& num  = funkcia(&num);
	return 0;
}

//______________________________________________________


*/
int& funkcia(const int& a) { //Reference
return a;
}

int main() {
int num = 5;
int& num = funkcia(&num);
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
