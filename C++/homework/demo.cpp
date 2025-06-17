#include <iostream>
#include <string>

/*
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
*/

class Address {
	public:
		std::string street;
		std::string	city;
		std::string	country;
};

class Person {
	public:
	std::string firstName;
	std::string lastName;
	Address homeAddress;
	Address workAddress;
	Person ( std::string f, std::string l) {
			firstName = f;
			lastName = l;
	};
		void print () {
			std::cout << firstName << " " << lastName << std::endl;
		}
};

class Employee : public Person{
	public:
		float salary;
		Employee (std::string f, std::string l, float s) : Person(f, l){
			salary = s;
		};
		void print() {
			Person::print();
			std::cout << salary << std::endl;
		}
};

int main() {
	Employee a("Karen", "Hakobjanyan", 150000);
	a.homeAddress.street = "Shinararneri 22/1";
	a.print();
	return 0;
}
