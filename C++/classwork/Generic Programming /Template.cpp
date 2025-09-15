#include <iostream>
#include <string>
#include <exception>


template <typename T> 
class Var {
	public:
	T value;
	void print() {
		std::cout << value << std::endl;
	}
};


template <typename T>
T add(T a, T b){
	return a + b;
}

template <typename T, typename T2>
T add(T a, T2 b){
	return a + b;
}

int main() {
	Var<int> myVar;
	// Var* myvar = new Var<int>(); heap->i mej
	myVar.value = 24;
	myVar.print();
	
	std::cout << add<T>(7, 9)<< std::endl;
	std::cout << add<T, T2>(8, true)<< std::endl;
	return 0;
}



template <typename T>
class Ban{
	public:
	T lvalue;
	T rvalue;
	
	Ban(T a, T b) : lvalue(a), rvalue(b) {}
	~Ban() {}
	
	Ban min(T lvalue, T rvalue){
		if(lvalue > rvalue){
			return rvalue;
		}
		return lvalue;
	}
	

	Ban max(T lvalue, T rvalue){
		if(lvalue < rvalue){
			return rvalue;
		}
		return lvalue;
	}


};

