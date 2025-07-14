#include <iostream>
#include <string>

class Animal{
	protected:
		std::string name;
		int age;
	public:
		Animal(){}
		Animal(std::string name, int age) {this->name = name; this->age = age;}
		~Animal(){}

	public:
		void setName( std::string name) { this->name = name;}
		std::string getName() {return this->name;}

		void setAge(int age) {this->age = age;}
		int getage() {return this->age;}

	public:
		virtual void Sound() {std::cout << "Unnown" << std::endl;}

};

class Dog : public Animal {
	protected:
		int weight;
	public:
	Dog() {}
	Dog(std::string, int name, int weight) {this->name = name; this->age = age; this->weight = weight;}
	~Dog() {}

	public:
		void Sound() {std::cout << "Woof" << std::endl;}
};

int main() {
	Animal* a = new Dog("Jeko", 4, 40);
	a->Sound();
	return 0;
}
