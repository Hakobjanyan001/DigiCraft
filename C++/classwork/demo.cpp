#include <iostream>
#include <string>
#include <memory>


/*
class Singleton{
private:
	static Singleton* obj;
private:
	Singleton()  {std::cout << "Ctor" << std::endl;}
	~Singleton() {}
public:
	static Singleton* getInstance() {
		if( nullptr == obj ) {
			obj = new Singleton();
		}	
		return obj;
	}
};

Singleton* Singleton::obj = nullptr;

int main() {
	Singleton* s1 = Singleton::getInstance();
	return 0;
}
*/

class Shape {
public:
	virtual void area() = 0;
};

class Circle : public Shape {
public:
	void area() override {
		std::cout << "Circle" << std::endl;
	}
};

class Rectangle : public Shape {
public:
	void area() override {
		std::cout << "Rectangle" << std::endl;
	}
};


class ShapeFactory {
public:
	static std::unique_ptr<Shape> createShape(const std::string type) {
		if( type == "Shrjan") return std::make_unique<Circle>();
		if( type == "Uxxankyun") return std::make_unique<Rectangle>();
		return nullptr;
	}
};

int main() {
	auto s1 = ShapeFactory::createShape("Shrjan");
	auto s2 = ShapeFactory::createShape("Uxxankyun");
	s1->area();
	s2->area();
return 0;
}
