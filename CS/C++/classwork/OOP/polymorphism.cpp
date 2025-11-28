#include <iostream>
#include <string>

class Animal {
public:
virtual void saund() {std::cout << "Unnown" << std::endl;}
};

class Cat : public Animal {
public:
void saund() {std::cout << "miau" << std::endl;}
};

class Dog : public Animal {
void saund() {std::cout << "haf" << std::endl;}
public:
};

class Horse : public Animal {
void saund() {std::cout << "xrxinj" << std::endl;}
public:
};

class Fish : public Animal {
public:
virtual void name() {std::cout << "Unnown name" << std::endl;} 
};

class Fish1 : public Fish {
public:
void name() {std::cout << "name: Fish1" << std::endl;} 
};

class Fish2 : public Fish {
public:
void name() {std::cout << "name: Fish2" << std::endl;} 
};

class Fish3 : public Fish {
public:
void name() {std::cout << "name: Fish3" << std::endl;} 
};

void printInfo(int a, int b) {std::cout << a << " " << b << std::endl;}

void printInfo(int a, std::string b) {std::cout << a << " " << b << std::endl;}
	
int main() {
// Polimorphism 
	Animal* animal[4];
	animal[0] = new Cat;
	animal[1] = new Dog;
	animal[2] = new Horse;
	animal[3] = new Animal;
	
	for(int i = 0; i < 4; i++) {
	animal[i]->saund();
	}

// Polimorphism
	Fish* fish[4];
	fish[0] = new Fish1;
	fish[1] = new Fish2;
	fish[2] = new Fish3;
	fish[3] = new Fish;
	for (int a = 0; a < 4; a++) {
	fish[a]->name();
	}

// Static funkcia, function overloading-i gaxapar
	printInfo(7, 9);	
	printInfo(7, "Karen");	
	return 0;
}
