#include <iostream>
#include <string>

class Person {
	private:
	int foo;
	public:
	std::string name;
	int age;
	int area();
	Person(std::string a, int t) {
		name = a;
		age = t;
		foo = 10;
	};
};

int Person::area() {
		return age * foo;
};

int main() {
	Person mard("Karen", 24);
	std::cout << mard.area() << std::endl;
	std::cout << mard.name << std::endl;
return 0;
}
