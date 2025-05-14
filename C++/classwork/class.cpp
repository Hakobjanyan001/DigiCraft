#include <iostream>
#include <string>

/*
struct student {
	std::string name;
	int grade;
};

int main() {
	std::string name1 = "";
	int grade1 = 0;
	std::cout << "Input your name " << std::endl;
	std::cin >> name1;
	std::cout << "Input your grade " << std::endl;
	std::cin >> grade1;
	student st1;
	st1.name = name1;
	st1.grade = grade1;
	if( grade1 < 0 ) {
		std::cout << "Vercru 0ic barcr tiv" << std::endl;
		return 1;
	}
	if( grade1 <= 40 ) {
		std::cout << "Qo gnahatakany D" << std::endl;
	} else if( grade1 <= 60 ) {
		std::cout << "Qo gnahatakany C" << std::endl;
	}  else if( grade1 <= 80 ) {
		std::cout << "Qo gnahatakany B" << std::endl;
	} else if( grade1 <= 100) {
		std::cout << "Qo gnahatakany A" << std::endl;
	} else {
		std::cout <<" vercru cacr tiv";
	}

	return 0;
}

*/


 struct employee {
	std::string name;
	int ashxatavardz;
	int porc;
};

int main() {
	employee kim;
	std::cout << "greq anuny: " << std::endl;
	std::cin >> kim.name;
	std::cout << "greq ashxatavardzy" << std::endl;
	std::cin >> kim.ashxatavardz;
	std::cout << "greq porcy" << std::endl;
	std::cin >> kim.porc;
	if( porc1 > 0  && porc1 < 2 ) {
		std::cout << "dzer bomnusy: " << ( ashxatavardz1 * 5 ) / 100 << std::endl;
	} else if( porc1 <= 5 ) { 
		std::cout << "dzer bonusy: " << ( ashxatavardz1 * 10 ) / 100 << std::endl;
	} else if( porc1 > 5) { 
		std::cout << "dzer bomnusy: " << ( ashxatavardz1 * 15 ) / 100 << std::endl;
	}

	return 0;
}
