#include <iostream>
#include <string>
class Employee{
	private:
		std::string name;
		float salory;
		int id;
	public:
		void setName(std::string name) {this->name = name;}
		std::string getName() {return this->name;}
		void setSalory(float salory) {this->salory = salory;}
		float getSalory() {return this->salory;}
		void setId(int id) {this->id = id;}
		int getId() {return this->id;}

		Employee() {}
		Employee(std::string name, float salory, int id ) : name(name), salory(salory), id(id) {}
		~Employee() {}
};

int main() {
	Employee e[3];
		std::string name;
		float salory;
		int id;
	float max = 0;
	int maxIndex = 0;
	for(int i = 0; i < 3; i++ ){
		std::cin >> name >> salory >> id;
		std::cout << i << " ashxatoxi tvyalner: " << name << " " << salory << " " << id << std::endl; 
	
	e[i].setName(name);
	e[i].setSalory(salory);
	e[i].setId(id);

		if(e[i].getSalory() >= max) {
			max = e[i].getSalory();
			maxIndex = i;

		}
	}
	std::cout << e[maxIndex].getName() << " " << e[maxIndex].getSalory() << std::endl;
}
