#include <iostream>
#include <string>


/*   struct person {
	int age;
	std::string name;
	std::string surname;
};

struct {
	std::string Brand;
	int year;
	std::string color;
}car1, car2;

int main() {
	person myPerson;
	myPerson.age  = 24;
	myPerson.name = "Karen";
	myPerson.surname = "Hakobjanyan";

	person ourPerson;
	ourPerson.age  = 25;
	ourPerson.name = "Aram";
	ourPerson.surname = "Saqanyan";

	std::cout << "age: " << myPerson.age  << std::endl << std::endl;
	std::cout << "name: " << myPerson.name  << std::endl << std::endl;
	std::cout << "surname: " << myPerson.surname  << std::endl << std::endl;

	std::cout << "age: " << ourPerson.age  << std::endl << std::endl;
	std::cout << "name: " << ourPerson.name  << std::endl << std::endl;
	std::cout << "surname: " << ourPerson.surname  << std::endl << std::endl;


	car1.Brand = "Yeraz";
	car1.year = 1981;
	car1.color = "kapuyt";

	car2.Brand = "maskvich";
	car2.year = 1999;
	car2.color = "seri";

	std::cout << "Brand: " << car1.Brand << std::endl << std::endl;
	std::cout << "year: " << car1.year << std::endl << std::endl;
	std::cout << "color: " << car1.color << std::endl << std::endl;

	std::cout << "Brand: " << car1.Brand << std::endl << std::endl;
	std::cout << "year: " << car1.year << std::endl << std::endl;
	std::cout << "color: " << car1.color << std::endl << std::endl;
	return 0;
}
*/



struct group {
std::string name;
std::string surname;
int age;
};

int main() {
	group Student1; 
	Student1.name = "Karen";
	Student1.surname = "Hakobjanyan";
	Student1.age = 24;
	
	group Student2; 
	Student2.name = "Erik";
	Student2.surname = "Khachatryan";
	Student2.age = 24;
	
	group Student3; 
	Student3.name = "Meri";
	Student3.surname = "Asryan";
	Student3.age = 19;
	
	group Student4; 
	Student4.name = "Valod";
	Student4.surname = "Voskanyan";
	Student4.age = 25;
	
	group Student5;
	Student5.name = "Gevorg";
	Student5.surname = "Asatryan";
	Student5.age = 21;
	
	group Student6;
	Student6.name = "Gor";
	Student6.surname = "Grigoryan";
	Student6.age = 22;

	std::cout << "Student1_Name: " << Student1.name << std::endl;
	std::cout << "Studnet1_Surname: " << Student1.surname << std::endl;
	std::cout << "Studnet1_age: " << Student1.age << "\n" <<std::endl;

	std::cout << "Student1_Name: " << Student2.name << std::endl;
	std::cout << "Studnet1_Surname: " << Student2.surname << std::endl;
	std::cout << "Studnet1_age: " << Student2.age << "\n" <<std::endl;

	std::cout << "Student1_Name: " << Student3.name << std::endl;
	std::cout << "Studnet1_Surname: " << Student3.surname << std::endl;
	std::cout << "Studnet1_age: " << Student3.age << "\n" <<std::endl;

	std::cout << "Student1_Name: " << Student4.name << std::endl;
	std::cout << "Studnet1_Surname: " << Student4.surname << std::endl;
	std::cout << "Studnet1_age: " << Student4.age << "\n" <<std::endl;

	std::cout << "Student1_Name: " << Student5.name << std::endl;
	std::cout << "Studnet1_Surname: " << Student5.surname << std::endl;
	std::cout << "Studnet1_age: " << Student5.age << "\n" <<std::endl;

	std::cout << "Student1_Name: " << Student6.name << std::endl;
	std::cout << "Studnet1_Surname: " << Student6.surname << std::endl;
	std::cout << "Studnet1_age: " << Student6.age << "\n" <<std::endl;

	return 0;
}
