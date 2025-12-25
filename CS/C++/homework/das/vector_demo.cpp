#include<iostream>
#include<string>

template <typename T>
class myVector : public std::exception{
private:
	T* m_arr;
	int m_size;
	int m_capacity;
	
	void resize(int newCapacity) {
		T* newArr = new T[newCapacity];
		for(int i = 0; i < m_size; i++) {
			newArr[i] = m_arr[i]; 
		}
		delete[] m_arr;
		m_arr = newArr;
		m_capacity = newCapacity;
	}

//Seter - Geter
public:
	myVector() : m_arr(nullptr), m_size(0), m_capacity(0) {}
	~myVector() { delete[] m_arr;}
	
// API
public:
	void push_back(T a) {
		if( m_capacity == m_size ) {
			resize(m_capacity == 0 ? 1 : m_capacity * 2 );
		}
		m_arr[m_size++] = a;
	}
	
	void pop_back() {
		if( m_size > 0 ) {
			m_size--; 
		}
	}

	int size() {
		return m_size;
	}

	int capacity() {
		return m_capacity;
	}
	
	void clear() {
		m_size = 0;
	}

	T at(int index) {
		try {
			if( index >= 0 && m_size > 0) {
				return m_arr[index];
			}
			throw new myVector();
		}catch(const std::exception* e) {
			std::cerr << "Error: " << e->what() << std::endl;
			return -1;
		}
	}

};

int main() {
	myVector<int>* vector = new myVector<int>();
	vector->push_back(5);
	vector->push_back(7);
	vector->push_back(9);
	vector->push_back(2);
	std::cout << "size: " << vector->size() << "\n";
	std::cout << "capacity: " << vector->capacity() << std::endl;
	vector->pop_back();
	vector->pop_back();
	std::cout << "size: " << vector->size() << "\n";
	std::cout << "capacity: " << vector->capacity() << std::endl;
	std::cout << "arr[1] = " << vector->at(1) << std::endl;
	std::cout << "arr[0] = " << vector->at(0) << std::endl;
return 0;
}
