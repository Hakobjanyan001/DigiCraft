#include <iostream>
#include <string>
#include <exception>
#include <memory>

//unique_ptr ________________________________________________
/*
int main() {
	st::unique _ptr<int> uPtr = std::_unique<int>(100);
	std::cout << *uPtr << std::endl;

	auto p = std::momve(uPtr);
	std::cout << *p << std::endl;

	if(uPtr != nullptr) {
	std::cout << *uPtr << std::endl;
	}

	return 0;
}

*/


/*
class Person {
public:
Person() { std::cout << "CTR" << std::endl;}
~Person() {std::cout << "DCTR" << std::endl;}
};

int main() {
	std::unique_ptr<Person> uPer = std::make_unique<Person>();
	//auto uPer = std::make_unique<Person>();  nuyn verevi toxna aveli karj
	*uPer;
	auto p = std::move(uPer);
	*p;
	return 0;
}
*/


//shared_ptr ________________________________________________________
/*
class Person {
public:
Person() { std::cout << "CTR" << std::endl;}
~Person() {std::cout << "DCTR" << std::endl;}
};

int main() {
	std::shared_ptr<Person> sPer = std::make_shared<Person>();
	//auto uPer = std::make_unique<Person>();  nuyn verevi toxna aveli karj
	*sPer;
	std::cout << sPer.use_count() << std::endl;
	{	
		auto p = sPer;
		*p;
		std::cout << sPer.use_count() << std::endl;;
	}
	return 0;
}
*/

//wea_ptr _____________________________________________________
/*
class Node{
	std::shared_ptr<Node> next;
	std::weak_ptr<Node> prev;
};

int main() {
	auto = std::make_shared<Node>(); 
	return 0;
}
*/


int main() {
	return 0;
}
