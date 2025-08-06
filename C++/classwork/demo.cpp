#include <iostream>
#include <string>
class Vector{
	private:
	int m_size;
	int m_capacity;
	int* m_arr;

	void resize(int newcapacity) {
		int* newarr = new int[newcapacity];
			for(int i = 0; i < m_size; i++) {
				newarr[i] = m_arr[i];
			}
		delete [] m_arr;
		m_arr = newarr;
		m_capacity = newcapacity;
	}

	public:
	Vector() : m_size(0), m_capacity(0), m_arr(0) {}
	~Vector() {delete [] m_arr;}

	void push_bac(int a) {
		if(m_size == m_capacity ) {
			resize(m_capacity == 0 ? 1 : m_capacity * 2 );
			m_arr[m_size++] = a;
		}
	}
	void pop_back() {m_size--;}
	int size() {return m_size; }
	int capacity() {return m_capacity;}
	void clear() {m_size = 0;}
	int at(int a) {return m_arr[a];}

};

int main(){
Vector* ve = new Vector();
ve->push_bac(53);
std::cout << ve->at(0) << std::endl;
return 0;
}
