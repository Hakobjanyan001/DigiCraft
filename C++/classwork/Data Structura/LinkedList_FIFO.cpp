#include <iostream>
#include <string>

class linkedListQueue {
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
Node* m_rearNode;
Node* m_topNode;
int m_size;
public:
	linkedListQueue() : m_size(0), m_rearNode(nullptr), m_topNode(nullptr) {}
	~linkedListQueue() {
			while(m_topNode) {
				Node* tmp = m_topNode;
				m_topNode = m_topNode->m_next;
				delete tmp;
			}
	}
//Public API
public:
	void enqueue(int value) {
		Node* newNode = new Node(value);
		if(m_rearNode == nullptr) {
			m_topNode = m_rearNode = newNode;
		} else {
			m_rearNode->m_next = newNode;
			m_rearNode = newNode;
		}	
		m_size++;
	}


	void dequeue() {
	
		if(isEmpty()) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}
		Node* tmp = m_topNode;
		m_topNode = m_topNode->m_next;
		if(m_topNode == nullptr) {
			m_rearNode = nullptr;
		}
		delete tmp;
		m_size--;
	}

	int size() {return m_size;}
	
	int get() {return m_topNode->m_value;}
	
	bool isEmpty() { return m_topNode == nullptr;}
};

int main() {
linkedListQueue* myList = new linkedListQueue();
myList->enqueue(7);
myList->enqueue(41);
myList->enqueue(23);
std::cout << myList->get() << std::endl;
std::cout << myList->size() << std::endl;
myList->dequeue();
std::cout << myList->get() << std::endl;
std::cout << myList->size() << std::endl;
	return 0;
}
