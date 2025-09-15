#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

// inchpes anel vor funkcian vorosh jamanak ush sksi
/*
void threadf(){
	std::cout << "Thread" << std::endl;
}

int main() {
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::thread t(threadf);
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	return 0;
}


//__________________________________________________________________________


// lambda funkcia 
int Sum(int a, int b) { return a + b; }

int main() {
int result; 
std::thread t([&result]() { result = Sum(2, 5); });
t.join();
std::cout << result << std::endl;
return 0;
}


//______________________________________________________________________________________________________________

// stexcuma Mutex obyekt bayc amen angam petqe chmorananq chmoranak lock() ev unlock() tarberak` lock_guard<std::miutex> guard(mtx)
// shat patokanoci depqum aveli hesht lock() unlock() ogtagorcel
std::mutex mtx;

void Print(char ch) {
  mtx.lock(); // blokavoruma hasaneliutyun miayn inqn uni datanin 
  for(int i = 0; i < 5; i++) {
  	for(int j = 0; j < 10; j++) {
		std::cout << ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	std::cout << std::endl; 
  }
  std::cout << std::endl; 
  mtx.unlock(); // blokavorumic dursgal 
}

int main() {

  std::thread t1(Print, '*');	
  std::thread t2(Print, '#');
  t1.join();
  t2.join();
  return 0;
}

*/



std::mutex mtx;
void Print(char ch) {
  std::lock_guard<std::mutex> guard(mtx); // avtomat anuma lock() ev unlock() erb obyekty skopic dursa gali 
					  // ete petqa shut unlock() ani mer uzac hatvacy dnel skocpi->{} mej 
  for(int i = 0; i < 5; i++) {
  	for(int j = 0; j < 10; j++) {
		std::cout << ch;
		std::this_thread::sleep_for(std::chrono::milliseconds(20)); // std::chrono::seconds(2) varkyanov
	}
	std::cout << std::endl; 
  }
  std::cout << std::endl; 
}

int main() {

  std::thread t1(Print, '*');	
  std::thread t2(Print, '#');
  t1.join();
  t2.join();
  return 0;
}
