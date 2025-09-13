#include <iostream>
#include <string>
#include <memory>

/*
int main() {
	st::unique_ptr<int> uPtr = std::make_unique<int>(100);
	std::cout << *uPtr << std::endl;

	auto p = std::momve(uPtr);
	std::cout << *p << std::endl;

	if(uPtr != nullptr) {
	std::cout << *uPtr << std::endl;
	}

	return 0;
}
*/



class Person {
public:
Person() { std::cout << "CTR" << std::endl;}
~Person() {std::cout << "DCTR" << std::endl;}
};

int main() {
	std::unique_ptr<Person> uPer = std::make_unique<Person>();
	//auto uPer = std::make_unique<Person>();  nuyn verevi toxna aveli karj
	*uPer;
	auto p = std::move(uPer);
	*p;
	return 0;
}


class Person{
private:
std::string name;
public:
Person(std::string name) : name(name){ std::cout << name << std::endl; }
~Person() { std::cout << "descasd" << std::endl; }
};

int main() {
	std::unique_ptr<Person> uPer = std::make_unique<Person>("Karen");
	*uPer;
	return 0;
}
