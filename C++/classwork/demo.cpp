#include <iostream>
#include <string>
/*
int calculator(int&, int&, char&);

int main() {
	int num1 = 0;
	int num2 = 0;
        char a = ' ';
	std::cin >> num1;
	std::cin >> num2;
	std::cin >> a;
	calculator(num1, num2, a);
	return 0;
}

int calculator(int& num1, int& num2, char& a) {
	if (a == '+') {
			          std::cout << num1 + num2  << std::endl;
             return num1 + num2;
	   } else if (a == '-') {
			          std::cout << num1 - num2  << std::endl;
		    return num1 - num2;
	          } else if (a == '*') {
			          std::cout << num1 * num2  << std::endl;
		         return num1 * num2;
	               } else if (a == '/') {
		              if(num1 >= num2){
			          return num1 / num2;
			          std::cout << num1 / num2  << std::endl;
	       	                } else {
			          std::cout << "Unnown" << std::endl;
				  return 0;
		              }
	                      } else {
		                     std::cout << "invalid operator" << std::endl;
				     return 0;
	                        }
}

enum x {MIANISH, ERKNISH, ERANISH, UNKNOWN};

x strToEnum (const std::string& s) {
	if(s == "MIANISH") {return MIANISH;} 
	if(s == "ERKNISH") {return ERKNISH;} 
	if(s == "ERANISH") {return ERANISH;} 
	std::cout << "Unknown" << std::endl;
	return UNKNOWN;
}

int main() {
std::string s = " ";
while (true) {
	std::cout << "MIANISH, ERKNISH, ERANISH" << std::endl;
	std::cin >> s;
        x tiv =	strToEnum(s);
	switch (tiv) {
	
		case MIANISH:
			for(int i = 0; i < 10; i++) {
				std::cout << i << std::endl;
			}
			break;
		
		case ERKNISH:
			for(int i = 10; i < 100; i++) {
				std::cout << i << std::endl;
			}
		        break;

		case ERANISH:
			for(int i = 100; i < 1000; i++) {
				std::cout << i  << std::endl;
			}
			break;

		default:
			std::cout << "input Unknown" << std::endl;
			break;

		}
}
return 0;
}


struct Student{
	std::string name;
	int age;
};

struct Employee{
	std::string name;
	float salory;
};

void print(Student);
void print(Employee);

int main(){
	
	Student st;
	st.name = "Karen";
	st.age = 24;

	Employee em;
	em.name = "Karen";
	em.salory = 155.900;

	print(st);
	print(em);
}

void print(Student st){
	std::cout << st.name << " " << st.age << std::endl;
}

void print(Employee em){
	std::cout << em.name << " " << em.salory << std::endl;
}
 


int arr(int a);


int arr(int a){
	std::cout << a * a << std::endl;
	return a * a;
}

int arr(int& a);

int arr(int& a){
	std::cout << a * a << std::endl;
	return a * a;
}
	std::cout << a * a << std::endl;
	return a * a;



int arr(int* a);

int arr(int* a){
	return *a =  *a * *a;
}
int main() {
	int a = 5;
	arr(&a);
	std::cout << a  << std::endl;
}

*/

void foo(int a[], int& z);

int main() {
	int lenght = 5;
	int arr[lenght] = {15, 25, 35, 45, 55};
	foo(arr, lenght);
	return 0;
}

void foo(int a[], int& z) {
	for(int i = 0; i < z; i++) {
		std::cout << a[i] << std::endl;
	}
}
