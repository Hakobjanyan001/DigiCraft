#include <iostream>
#include <string>
#include <exception>


int main() {
	int a = 1;
	int b = 0;
	try{
		if( b == 0) {
			throw "Division by 0 Exception";
		}
		std::cout << a / b << std::endl;
	} catch ( const char* msg) {
		std::cout << "Error: " << msg << std::endl;
	}
	return 0;
}


void safe() noexcept {
 // noexcept => ay funkcianery cucen tali vor chi kara exception unena ira mej kam ete uniel inqy da lucuma
}


int main() {
		safe();
	return 0;
}

void c();
int devaid(int& a, int& b);

int main() {
	c();
	return 0;
}
void c() {
	int a = 10;
	int b = 0;
	try{
	devaid(a, b);
	} catch(const char* msg ) {
		std::cout << "Error: " << msg << std::endl;
	}
}

int devaid(int& a, int& b) {
	if (b == 0 ) {
		throw "Dvision by 0 Exception";
	}
	return a / b;
}


class MyException : public std::exception {
public:
	const cahr* what() const noexcept override{
		return "my exception";
	}
};

void f(){
	throw new MyException();
}

int main() {
	try{
		f();		
	} catch ( const MyException* e) {
		std::cout << "Error: " << e->what() << std::endl;
	}
	return 0;
}





