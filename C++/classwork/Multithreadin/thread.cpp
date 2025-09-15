#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>


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

*/

std::mutex mtx;
std::condition_variable cv;
std::queue<int> container;
int size = 5;

void producer(){
	for(int i = 0; i < 10; i++) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [] { return container.size() < size;});
		std::cout << "Adding " << i << std::endl;
		container.push(i);
		cv.notify_all();
	}
}

void consumer() {
	for(int i = 0; i < 10; i++) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [] { return !container.empty();});
		std::cout << "Consuming " << std::endl;
		container.pop();
		cv.notify_all();
	}
}

int main() {
	std::thread t1(producer);
	std::thread t2(consumer);
	t1.join();
	t2.join();
	return 0;
}
