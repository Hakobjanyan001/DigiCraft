#include <iostream>
#include <string>

class Shape{
	protected:
	float r;
	float layn;
	float erk;

	public:
	Shape(){}
	Shape(const float r, float layn, float erk) : r(r), layn(layn), erk(erk){}
	~Shape(){}
	float getR() {return this->r;}
	float getLayn() {return this->layn;}
	float getErk() {return this->erk;}

	virtual void area(){
		std::cout << "Unknown" << std::endl;
	}
};

class Rectangle : public Shape{
	public:
	Rectangle(){}
	Rectangle(const float r, float layn, float erk) : Shape(r,layn, erk){}
	~Rectangle(){}

	virtual void area(){
		std::cout << "Rectangle: " << r * erk * layn << std::endl;
	}
};

class Triangle : public Shape{
	public:
	Triangle(){}
	Triangle(const float r, float layn, float erk) : Shape(r,layn, erk){}
	~Triangle(){}
	virtual void area(){
		std::cout << "Triangle: " << r*  r * erk * layn << std::endl;
	}
};

int main() {
Shape* t = new Triangle(3.14, 3, 4);
t->area();

Shape* r= new Rectangle(3.14, 3, 4);
r->area();
}

/*
class Student{
	protected:
		std::string* name;
		float* grade;
	public:
		Student(){}
		Student(std::string* name, float* grade) : name(new std::string(* name)), grade(new float(* grade)){}
		~Student(){delete name; delete grade;}

		std::string getName(){return * name;}
		float getGrade(){return* grade;}
};

int main(){
	std::string name;
	float grade;
	float sum = 0;
	Student* a = new Student[5];
	for(int i = 0; i < 5; i++){
		std::cin >> name >> grade;
		a[i] = Student(&name, &grade);
		sum += grade;
	}
	std::cout << sum / 5 << std::endl;
}
*/
