#include <iostream>
#include <string>

class My_vector{
	
	private:
	int m_size;
	int m_capacity;
	int* m_arr;

	void resize( int newcap) {
		int* newarr = new int[newcap];
		for(int i = 0; i < m_size; i++) {
			newarr[i] = m_arr[i];
		}
			delete[] m_arr;
			m_arr = newarr;
			m_capacity = newcap;
	}
	
	public:
	My_vector() : m_size(0), m_capacity(0), m_arr(nullptr) {}
	~My_vector() {delete[] m_arr;}
	
	void push_back( int a ) {
		if(m_size == m_capacity) {
			resize( m_capacity == 0 ? 1 : m_size * 2 );
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

	int add(int a) {return m_arr[a];}
};

int main(){

My_vector* vector = new My_vector();

for(int i = 0; i < 5; i++ ){
	vector->push_back(i * 2);
	std::cout << i << "-erord andamy: " <<  vector->add(i) << std::endl;
}

std::cout << "\nzangvaci chapy: " << vector->size() << "\n" << std::endl;

vector->pop_back();

std::cout << "zangvaci chapy pop_back()-ic heto: " << vector->size() << "\n" << std::endl;

std::cout << "zangvaci mej azat indeqsneri chapy :" << vector->capacity() << "\n" << std::endl;

vector->clear();
std::cout << "zangvaci chapy clear()-ic heto: " << vector->size() << std::endl;

return 0;
}
