#include <iostream>
#include <string>
class Animal{
	
	public:
	Animal() {}
	Animal(std::string name, std::string sound) : name(name), sound(sound) {}
	~Animal() {}
	
	public:
	std::string getName() {return this->name;}

	std::string getSound() {return this->sound;}
	
	public:
	virtual void printInfo(){
		std::cout << name << " " << sound << std::endl;
	}

	protected:
	const std::string name;
	const std::string sound;
};

class Dog : public Animal{
	public:
	Dog(std::string name, std::string sound, int weight) : Animal(name, sound), weight(weight) {}

	void printInfo(){
		std::cout << name << " " << sound << " " << weight << std::endl;
	}
	
	protected:
	int weight;
};

int main() {
	Animal* an = new Dog("Jeko", "Haf", 75);
	an->printInfo();
	return 0;
}
