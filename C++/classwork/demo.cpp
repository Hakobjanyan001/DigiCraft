#include <iostream>
#include <string>
class Student{
public:
	Student();
	~Student();
	void setName( std::string naem);
	std::string getName();
	void setSurname( std::string surnaem);
	std::string getSurname();
	void setAge( int age);
	int getAge();
	void printStudentInfo();
private:
	std::string m_name;
	std::string m_surname;
	int m_age;

};
Student::Student() {
m_name = " ";
m_surname = " ";
m_age = 0;
}


void Student::setName(std::string name) {
	m_name = name;
}

std::string Student::getName() {
	return m_name;
}

void Student::setSurname(std::string surname) {
	m_surname = surname;
}

std::string Student::getSurname() {
	return m_surname;
}

void Student::setAge(int age) {
	m_age = age;
}

int Student::getAge() {
 return m_age;
}

void Student::printStudentInfo() {
	std::cout << m_name << "\t" << m_surname << "\t" << m_age << std::endl;
}

Student::~Student() {
}

int main() {
	Student st;
	st.setName("Karen");
	st.setSurname("Hakobjanyan");
	st.setAge(24);
	st.printStudentInfo();
 return 0;
}
