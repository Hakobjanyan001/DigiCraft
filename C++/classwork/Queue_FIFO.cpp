#include <iostream>
#include <string>
class ArrayQueue{
// Member data
private:
	int* m_arr;
	int m_capacity;
	int m_topIndex;
	int m_count;
	int m_rearIndex;

// Special Function
public:
	ArrayQueue(int cap = 10) : m_capacity(cap), m_rearIndex(-1), m_topIndex(0), m_count(0)  {m_arr = new int[m_capacity];}
	~ArrayQueue() { delete [] m_arr; }

// public API
	void enqueue(int value) {
		if(m_rearIndex + 1 == m_capacity) {
			std::cout << "stack overflow" << std::endl;
			return ;
		} 
		m_rearIndex = (m_rearIndex + 1) % m_capacity; // ete uzumenq anverj avelacnel nuyn chapani zangvaci mej 
		m_arr[m_rearIndex] = value;
		m_count++;
	}

	void dequeue() {
		if(isEmpty()) {
			std::cout << "ArrayQueue is empty" << std::endl;
		}
		m_topIndex++;
		m_count--;
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
		return m_count;
	}
};


int main() {
	ArrayQueue* myStac = new ArrayQueue();
	myStac->enqueue(3);
	myStac->enqueue(8);
	std::cout << myStac->top() << std::endl;
	std::cout << myStac->size() << std::endl;
	myStac->dequeue();
	std::cout << myStac->top() << std::endl;
	std::cout << myStac->size() << std::endl;
	return 0;
}
