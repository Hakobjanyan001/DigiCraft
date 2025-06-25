#include <iostream>
#include <string>

class Person
{
// Ctor/Dtor
public:
Person();
Person(std::string name, int age);
~Person();

//Str/Gtr
public:
void setName(std::string name);
std::string getName();

void setAge(int age);
int getAge();

void PrintInfo();

protected:
std::string name;
int age;
};

Person::Person(){
this->name = " ";
this->age = 0;
}

Person::Person(std::string name, int age){
this->name = name;
this->age = age;
}

Person::~Person(){

}

void Person::setName(std::string name){
this->name = name;
}

std::string Person::getName(){
return this->name;
}

void Person::setAge(int age){
this->age = age;
}

int Person::getAge(){
return this->age;
}

void Person::PrintInfo(){
	std::cout << this->name << " " << this->age << std::endl;
}

class Student : public Person 
{
protected:
int grade;

public:
Student(){this->name = " ";
this->age = 0;
this->grade = 0;}
Student(std::string name, int age, int grade){this->name = name;
this->age = age;
this->grade = grade;}
~Student(){}

public:
void setGrade(std::string name, int age, int grade){this->grade = grade;}

int getGrade(){return this->grade;}

void PrintInfo(){std::cout << this->name << " "<< this->age << "  " << this->grade << std::endl;}
};

class Teacher : public Person 
{
protected:
std::string lectuare;

public:
Teacher(){this->name = " ";
this->age = 0;
this->lectuare = " ";}
Teacher(std::string name, int age, std::string lectuare){this->name = name;
this->age = age;
this->lectuare = lectuare;}
~Teacher(){}

public:
void setLectuare(std::string name, int age, std::string lectuare){this->lectuare = lectuare;}

std::string getLectuare(){return this->lectuare;}

void PrintInfo(){std::cout << this->name << " " << this->age << " " << this->lectuare << std::endl;
};

};

int main() {
	Person p("Kren", 24);
	p.PrintInfo();
	Student st("Kren", 24, 70);
	st.PrintInfo();
	Teacher t("Kren", 24, "Cragravorum");
	t.PrintInfo();
	return 0;
}
