#include <iostream>
#include <string>


template <typename T>
class linkedList {
// Node Struct
private:
struct Node {
	public:
		T m_data; 
		Node* m_next; 

		Node(T value) : m_data(value), m_next(nullptr) {}
		~Node() {}
};

// Member Data
private:
Node* m_head;
int m_size;
public:
	linkedList() : m_head(nullptr), m_size(0) {}
	~linkedList() {
			while(m_head) {
				Node* tmp = m_head;
				m_head = m_head->m_next;
				delete tmp;
			}
	}
//Public API
	public:
	void push_back(T value) {
		Node* newNode = new Node(value);
		if(!m_head) {
		m_head = newNode;
		}else {
			Node* curr = m_head;
			while(curr->m_next) {
				curr = curr->m_next;
			}
			m_size++;
		}
	}
	void pop_back() {
		if(!m_head) {
			return;
		}
		if(!m_head->m_next) {
			delete m_head;
			m_head = nullptr;
		} else {
			Node* curr = curr->m_next;
			while(curr->m_next) {
				curr = curr->m_next;
			}
			delete curr->m_next;
			curr->m_next = nullptr;
		}
		m_size--;
	}

	int size() {return m_size;}

	T at(T value) {
		Node* curr = m_head;
			for(int i = 0; i < value; i++) {
				curr = curr->m_next;
			}
			return curr->m_data;
	}
};

int main() {
linkedList<int>* myList = new linkedList<int>();
myList->push_back(7);
myList->push_back(41);
myList->push_back(23);
std::cout << myList->at(2) << std::endl;
std::cout << myList->size() << std::endl;
myList->pop_back();
std::cout << myList->at(1) << std::endl;
std::cout << myList->size() << std::endl;
	return 0;
}
