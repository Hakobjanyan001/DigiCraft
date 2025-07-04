#include <iostream>
#include <string>

class Animal{
public:
Animal(std::string& name) : 
	name(name){
}
std::string getName(){
return this->name;
}
protected:
const std::string& name;
};

class Fish : public Animal{
public:
Fish(std::string name, int size) : 
	Animal(name),
	size(size){
	}
int getSize(){
return this->size;
}
protected:
int size;
};

class Shark : public Fish{
public:
Shark(std::string name, int size, int weight) :
	Fish(name, size),
	weight(weight){
	}
int getWeight(){
return this->weight;
}
private:
int weight;
};

int main() {
	std::string name = "Akula";
	Shark sh(name, 4, 55);
	std::cout << sh.getName() << " " <<sh.getSize() << " " <<  sh.getWeight()  << std::endl;
	return 0;
}
