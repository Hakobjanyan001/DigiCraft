#include<iostream>
#include<string>
class Singlton{
private:
	static Singlton* obj;
	Singlton() = default;

	Singlton(const Singlton& other) = delete;
	Singlton& operator=(const Singlton& other) = delete;

	Singlton(Singlton&& other) = delete;
	Singlton& operator=(Singlton&&) = delete;

public:
	static Singlton* getInstance() {
		if( obj == nullptr ) {
			obj = new Singlton();
		}
		return obj;
	}

	static void deletePtr() {
		if(obj != nullptr) {
			delete obj;
			obj = nullptr;
		}
	}
};

Singlton* Singlton::obj = nullptr;

int main() {
	Singlton* s1 = Singlton::getInstance();
	Singlton* s2 = Singlton::getInstance();
	
	std::cout << s1 << "\t" << s2 << "\n";
		
	s1->deletePtr();
	s2->deletePtr();
return 0;
}
