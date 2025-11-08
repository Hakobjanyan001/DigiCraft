#include <iostream>
#include <string>

class Employee {
	// Voch hasaneli bolorin
	private:
	std::string name;
	int salary;
	int year;

	// Cotr
	public:
	Employee();
	Employee(std::string name, int salary, int year);
	
	// Dotr
	public:
	~Employee();

	// Str/Gtr
	void setName(std::string name);
	std::string getName();

	void setSalary(int salary);
	int  getSalary();

	void setYear(int year);
	int getYear();

	// Utilitie
	public:
	void square();
	void printEmployeeInfo();
};

Employee::Employee()
{
	this->name = " ";
	this->salary = 0;
	this->year = 0;
}

Employee::Employee(std::string name, int salary, int year)
{
	this->name = name;
	this->salary = salary;
	this->year = year;
}

Employee::~Employee()
{

}

void Employee::setName(std::string name)
{
	this->name = name;
}

std::string Employee::getName()
{
	return this->name;
}

void Employee::setSalary(int salary)
{
	this->salary = salary;
}

int Employee::getSalary()
{
	return this->salary;
}

void Employee::setYear(int year)
{
	this->year = year;
}

int Employee::getYear()
{
	return this->year;
}
	
void Employee::square()
{
	if(year >= 5) {
		std::cout << "ashxatavardzy kbardzrana 15 % ov` " << (this->salary * 15) / 100 << std::endl;
	} else if(year >= 1) {
				std::cout << "ashxatavardzy kbardzrana 10 % ov` " << (this->salary * 10) / 100 << std::endl;
			} else {
					std::cout << "ashxatavardzy kbardzrana 5 % ov` " << (this->salary * 5) / 100 << std::endl;
				}
}

void Employee::printEmployeeInfo() 
{
	std::cout << "anun " << this->name << std::endl;
	std::cout << "ashxatavardz " << this->salary << std::endl;
	std::cout << "ashxatanqain tari " << this->year << std::endl;
}
		
int main() {

	std::string name = " ";
	int salary = 0;
	int year = 0;

	std::cout << "greq dzer anuny" << std::endl;
	std::cin >> name;
	std::cout << "greq dzer ashxatavardzy" << std::endl;
	std::cin >> salary;
	std::cout << "greq dzer ashxatanqain pordzy" << std::endl;
	std::cin >> year;

	if (year <=  0 || salary <= 0) {
		std::cout << "ERROR" << std::endl;
	} else {
	Employee hm(name, salary, year);
	hm.square();
	hm.printEmployeeInfo();
	}
	return 0;
}
