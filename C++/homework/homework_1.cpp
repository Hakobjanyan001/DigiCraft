#include <iostream>
#include <string>

class Human {
	// Voch hasaneli bolorin
	private:
	std::string name;
	int salaryee;
	int year;

	// Cotr
	public:
	Human();
	Human(std::string name, int salaryee, int year);
	
	// Dotr
	public:
	~Human();

	// Str/Gtr
	void setName(std::string name);
	std::string getName();

	void setSalaryee(int salaryee);
	int  getSalaryee();

	void setYear(int year);
	int getYear();

	// Utilitie
	public:
	void square();
	void printHumanInfo();
};

Human::Human()
{
	this->name = " ";
	this->salaryee = 0;
	this->year = 0;
}

Human::Human(std::string name, int salaryee, int year)
{
	this->name = name;
	this->salaryee = salaryee;
	this->year = year;
}

Human::~Human()
{

}

void Human::setName(std::string name)
{
	this->name = name;
}

std::string Human::getName()
{
	return this->name;
}

void Human::setSalaryee(int salaryee)
{
	this->salaryee = salaryee;
}

int Human::getSalaryee()
{
	return this->salaryee;
}

void Human::setYear(int year)
{
	this->year = year;
}

int Human::getYear()
{
	return this->year;
}
	
void Human::square()
{
	if(year >= 5) {
		std::cout << "ashxatavardzy kbardzrana 15 % ov` " << (this->salaryee * 15) / 100 << std::endl;
	} else if(year >= 1) {
				std::cout << "ashxatavardzy kbardzrana 10 % ov` " << (this->salaryee * 10) / 100 << std::endl;
			} else {
					std::cout << "ashxatavardzy kbardzrana 5 % ov` " << (this->salaryee * 5) / 100 << std::endl;
				}
}

void Human::printHumanInfo() 
{
	std::cout << "anun " << this->name << std::endl;
	std::cout << "ashxatavardz " << this->salaryee << std::endl;
	std::cout << "ashxatanqain tari " << this->year << std::endl;
}
		
int main() {

	std::string name = " ";
	int salaryee = 0;
	int year = 0;

	std::cout << "greq dzer anuny" << std::endl;
	std::cin >> name;
	std::cout << "greq dzer ashxatavardzy" << std::endl;
	std::cin >> salaryee;
	std::cout << "greq dzer ashxatanqain pordzy" << std::endl;
	std::cin >> year;

	if (year <=  0 || salaryee <= 0) {
		std::cout << "ERROR" << std::endl;
	} else {
	Human hm(name, salaryee, year);
	hm.square();
	hm.printHumanInfo();
	}
	return 0;
}
