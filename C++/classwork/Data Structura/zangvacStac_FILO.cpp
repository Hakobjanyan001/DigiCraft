#include <iostream>
#include <string>
class ArrayStac{
// Member data
private:
	int* m_arr;
	int m_capacity;
	int m_topIndex;

// Special Function
public:
	ArrayStac(int cap = 10) : m_capacity(cap), m_topIndex(-1) {m_arr = new int[m_capacity];}
	~ArrayStac() { delete [] m_arr; }

// public API
	void push_back(int value) {
		if(m_topIndex + 1 == m_capacity) {
			std::cout << "stack overflow" << std::endl;
			return ;
		} 
		m_arr[++m_topIndex] = value;
	}

	void pop() {
		if(isEmpty()) {
			std::cout << "ArrayStac is empty" << std::endl;
		}
		--m_topIndex;
	}

	int top() {
		if(isEmpty()) {
			std::cout << "Array is empty" << std::endl;
			return -1;
		}
		return m_arr[m_topIndex];
	}

	bool isEmpty() {
		return m_topIndex == -1;
	}

	int size() {
		return m_topIndex + 1;
	}
};


int main() {
	ArrayStac* myStac = new ArrayStac();
	myStac->push_back(3);
	myStac->push_back(8);
	std::cout << myStac->top() << std::endl;
	std::cout << myStac->size() << std::endl;
	myStac->pop();
	std::cout << myStac->top() << std::endl;
	std::cout << myStac->size() << std::endl;
	return 0;
}
