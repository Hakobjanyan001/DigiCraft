#include <iostream>
#include <string>
#include <memory>

class Person {
public:
Person() { std::cout << "CTR" << std::endl;}
~Person() {std::cout << "DCTR" << std::endl;}
};

int main() {
	std::shared_ptr<Person> sPer = std::make_shared<Person>();
	//auto uPer = std::make_unique<Person>();  nuyn verevi toxna aveli karj
	*sPer;
	std::cout << sPer.use_count() << std::endl; // use_count() sa funkcia e vory cuyce tali arjeqy ev nuyn hascenein uxxvac cucichneri qanaky
	{	
		auto p = sPer;
		*p;
		std::cout << sPer.use_count() << std::endl;;
	}
	return 0;
}
