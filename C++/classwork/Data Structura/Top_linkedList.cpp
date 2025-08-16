#include <iostream>
#include <string>

class linkedListStac {
// Node Struct
private:
struct Node {
	public:
		int m_value; 
		Node* m_next; 

		Node(int value) : m_value(value), m_next(nullptr) {}
		~Node() {}
};

// Member Data
private:
Node* m_topNode;
int m_size;
public:
	linkedListStac() : m_size(0), m_topNode(nullptr) {}
	~linkedListStac() {
			while(m_topNode) {
				Node* tmp = m_topNode;
				m_topNode = m_topNode->m_next;
				delete tmp;
			}
	}
//Public API
	public:
	void push_back(int value) {
		Node* newNode = new Node(value);
		newNode->m_next = m_topNode;
		m_topNode = newNode;
		m_size++;	
	}


	void pop_back() {
		Node* tmp = m_topNode;
		m_topNode = m_topNode->m_next;
		delete tmp;
		m_size--;
	}

	int size() {return m_size;}
	
	int get() {return m_topNode->m_value;}
	
	bool isEmpty() { return m_topNode = nullptr;}
};

int main() {
linkedListStac* myList = new linkedListStac();
myList->push_back(7);
myList->push_back(41);
myList->push_back(23);
std::cout << myList->get() << std::endl;
std::cout << myList->size() << std::endl;
myList->pop_back();
std::cout << myList->get() << std::endl;
std::cout << myList->size() << std::endl;
	return 0;
}
