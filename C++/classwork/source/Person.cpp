#include <iostream>
#include "../hider/Person.h"

	Person::Person(int age, std::string name) : m_age(age), m_name(name) {}
	
	int Person::getAge() {
		return m_age;
	}

	std::string Person::getName() {
		return m_name;
	}
	
	void Person::printInfo() {	
		std::cout << "Age: " << getAge() << "\nName: " << getName() << std::endl;
	}
