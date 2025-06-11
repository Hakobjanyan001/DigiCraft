#include <iostream>
#include <string>

// std::cout << sizeof(std::string) << std::endl;	

/*
struct Student{
	std::string* pName = nullptr;
	int* pGrad = nullptr;
};

int main(){
	Student* pStudent = new Student();
	pStudent->pName = new std::string("Karen");
	pStudent->pGrad = new int(24);
	//(*pStudent).pName = new std::string("Karen");
	//(*pStudent).pGrad = new int(24);
	std::cout << *(pStudent->pName) << std::endl;
	std::cout << *(pStudent->pGrad) << std::endl;
	//std::cout << *((pStudent).pName) << std::endl;
	//std::cout << *((pStudent).pGrad) << std::endl;
	delete pStudent->pName;
	delete pStudent->pGrad;
	delete pStudent;
	//delete (*pStudent).pName;
	//delete (*pStudent).pGrad;
	

return 0;
}
*/

struct Student{
	std::string* pName = nullptr;
	int* pGrad = nullptr;
};

int  main(){
	Student* pStudent = new Student();
	pStudent->pName = new std::string("Karen");
	(*pStudent).pGrad = new int(72);
	std::cout << *(pStudent->pName) << std::endl;
	std::cout << *((pStudent).pGrad) << std::endl;
	delete pStudent->pName;
	delete (*pStudent).pGrad;
	delete pStudent;
	return 0;
}
