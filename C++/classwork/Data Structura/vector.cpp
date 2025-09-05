#include <iostream>
#include <string>

template <typename T>
class Myvector{
	
	private:
	int m_size;
	int m_capacity;
	T* m_arr;

	void resize( int newcap) {
		T* newarr = new T[newcap];
		for(int i = 0; i < m_size; i++) {
			newarr[i] = m_arr[i];
		}
			delete[] m_arr;
			m_arr = newarr;
			m_capacity = newcap;
	}
	
	public:
	Myvector() : m_size(0), m_capacity(0), m_arr(nullptr) {}
	~Myvector() {delete[] m_arr;}
	
	void push_back( T a ) {
		if(m_size == m_capacity) {
			resize( m_capacity == 0 ? 1 : m_capacity*2);
		}	
		m_arr[m_size++] = a;
	}

	void pop_back() {
		if(m_size > 0) {
			m_size--;
		}
	}

	int size() {return m_size;}

	int capacity() {return m_capacity;}

	void clear () {m_size = 0;}

	T at(int index) {
		if(index >= 0 && index < m_size) {
			return m_arr[index];
		}
		return -1;
	}
};

int main(){

Myvector<int>* vector = new Myvector<int>();  // < int>, <std::string> (< >)-> i mej nshel tayp

for(int i = 0; i < 5; i++ ){
	vector->push_back(i * 2);
	std::cout << i << "-erord andamy: " << vector->at(i) << std::endl;
}

std::cout << "\nzangvaci chapy: " << vector->size() << "\n" << std::endl;

vector->pop_back();

std::cout << "zangvaci chapy pop_back()-ic heto: " << vector->size() << "\n" << std::endl;

std::cout << "zangvaci mej azat indeqsneri chapy :" << vector->capacity() << "\n" << std::endl;

vector->clear();
std::cout << "zangvaci chapy clear()-ic heto: " << vector->size() << std::endl;

delete vector;
return 0;
}
