#ifndef __PERSON__H
#define __PERSON__H

#include <iostream>
#include <string>

class Person {
private:
	int m_age;
	std::string m_name;
public:
	Person(int age, std::string name);
	

public:
	int getAge();
	std::string getName();
	void printInfo();
}; 

#warning "Include meny ../Person.h"
#endif // _PERSON_H
