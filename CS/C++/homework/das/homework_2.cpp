#include <iostream>
#include <string>

class Car {
	// Voch hasaneli bolorin
	private:
	std::string name;
	std::string producer; // vor erkirn e artadrum 
	int year;

	// Cotr
	public:
	Car();
	Car(std::string name, std::string producer, int year);
	
	// Dotr
	public:
	~Car();

	// Str/Gtr
	void setName(std::string name);
	std::string getName();

	void setProducer(std::string producer);
	std::string  getProducer();

	void setYear(int year);
	int getYear();

	// Utilitie
	public:
	void car_year();
	void printCarInfo();
};

Car::Car()
{
	this->name = " ";
	this->producer = " ";
	this->year = 0;
}

Car::Car(std::string name, std::string producer, int year)
{
	this->name = name;
	this->producer = producer;
	this->year = year;
}

Car::~Car()
{

}

void Car::setName(std::string name)
{
	this->name = name;
}

std::string Car::getName()
{
	return this->name;
}

void Car::setProducer(std::string producer)
{
	this->producer = producer;
}

std::string Car::getProducer()
{
	return this->producer;
}

void Car::setYear(int year)
{
	this->year = year;
}

int Car::getYear()
{
	return this->year;
}
	
void Car::car_year()
{
	int x = 2025 - year;
	std::cout << "dzer meqenan " << x << "tarekan e:\n" << std::endl;
}

void Car::printCarInfo() 
{
	std::cout << "meqenai anun " << this->name << std::endl;
	std::cout << "meqenai artadrox erkir " << this->producer << std::endl;
	std::cout << "artadrman tari " << this->year << std::endl;
}
		
int main() {

	std::string name = " ";
	std::string producer = " ";
	int year = 0;

	std::cout << "greq dzer meqenayi anuny" << std::endl;
	std::cin >> name;
	std::cout << "vor erkrne artadrum  meqenan" << std::endl;
	std::cin >> producer;
	std::cout << "greq vor tvi artadrutyan e meqenan" << std::endl;
	std::cin >> year;

	if (year > 2025) {
		std::cout << "meqenan der artadrvac che:" << std::endl;
	} else {
	Car c(name, producer, year);
	c.car_year();
	c.printCarInfo();
	}
	return 0;
}
