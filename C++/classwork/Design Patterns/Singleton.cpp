#include <iostream>
#include <string>
#include <memory>


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
	Singleton* s2 = Singleton::getInstance();
	std::cout << s1 << "\n" << s2 << std::endl;
	return 0;
}
