#include <iostream>
#include <string>
#include <thread>


/*
void threadf(){
	std::couit << "Thread" << std::endl;
}

int main() {
	std::thread t(threadf);
	if( t.join()) {
	t.join(); //spasi
	}
	t.detach(); //chspasi 
	return 0;
}




void Hello(std::string name){
	std::couit << "Hello " << name << std::endl;
}

int main(std::string name) {
	std::thread t(Hello, "Karen");
	if( t.join()) {
	t.join(); //spasi
	}
	t.detach(); //chspasi 
	return 0;
}

*/


void Hello(std::string& name){
	name = "Poxos"
	std::couit << "Hello " << name << std::endl;
}

int main() {
	st::string str = "Karen"
	std::thread t(Hello, std::ref(str));
	t.detach(); //chspasi 
	std::cout << str << std::endl;
	return 0;
}
