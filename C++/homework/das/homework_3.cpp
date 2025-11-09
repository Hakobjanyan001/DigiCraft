#include <iostream>
#include <string>

class Dog {
	// Voch hasaneli bolorin
	private:
	std::string name;
	int weight;
	int age;

	// Cotr
	public:
	Dog();
	Dog(std::string name, int weight, int age);
	
	// Dotr
	public:
	~Dog();

	// Str/Gtr
	void setName(std::string name);
	std::string getName();

	void setWeight(int weight);
	int  getWeight();

	void setAge(int age);
	int getAge();

	// Utilitie
	public:
	void Dog_breed(); // shan cexatesak
	void Dog_timeToLive(); 
};

Dog::Dog()
{
	this->name = " ";
	this->weight = 0;
	this->age = 0;
}

Dog::Dog(std::string name, int weight, int age)
{
	this->name = name;
	this->weight = weight;
	this->age = age;
}

Dog::~Dog()
{

}

void Dog::setName(std::string name)
{
	this->name = name;
}

std::string Dog::getName()
{
	return this->name;
}

void Dog::setWeight(int weight)
{
	this->weight = weight;
}

int Dog::getWeight()
{
	return this->weight;
}

void Dog::setAge(int age)
{
	this->age = age;
}

int Dog::getAge()
{
	return this->age;
}
	
void Dog::Dog_breed()
{
	if(weight <= 10){
	std::cout << "nman shan cexatesaky tuzik e" << std::endl;
	} else if (weight <= 70) {
		std::cout << "nman shan cexatesaky doberman, xaski, pitbul" << std::endl;
		} else {
			std::cout << "nman shan cexatesaky gampr, alaba, mastif" << std::endl;
			}
}

void Dog::Dog_timeToLive()
{
	if(age <= 8){
	std::cout << " dzer shuny uni shat tari aprelu: " << std::endl;
	} else {
		std::cout << "dzer shan mijin aprelu tariqy poqr e:" << std::endl;
		}
}

		
int main() {

	std::string name = " ";
	int weight = 0;
	int age = 0;

	std::cout << "shan anuny " << std::endl;
	std::cin >> name;
	std::cout << "qashy" << std::endl;
	std::cin >> weight;
	std::cout << "tariqy" << std::endl;
	std::cin >> age;

	if (weight <= 0 || age <= 0) {
		std::cout << "Nman shun chi karox linel;" << std::endl;
	} else {
	Dog c(name, weight, age);
	c.Dog_timeToLive();
	c.Dog_breed();
	}
	return 0;
}
