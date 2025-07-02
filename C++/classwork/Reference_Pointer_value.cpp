#include <iostream>
#include <string>

int funkcia(const int a) { //Value
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



int& funkcia(const int& a) { //Reference
return a;
}

int main() {
int num = 5;
int& num = funkcia(&num);
	return 0;
}
