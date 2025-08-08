#include <iostream>
#include <string>
struct Node {
	int m_data; 
	Node* m_next; // cucich depi hajord Node

	Node(int value) : m_data(value), m_next(nullptr) {}
	~Node() {}
};

class linkedList {
private:
	Node* m_head; // cucich depi arajin Node
	
public:
	linkedList() : m_head(nullptr) {}
	~linkedList() {}

	void push_front(int value) {
		Node* newNode = new Node(value);
		newNode->m_next = m_head;
		m_head = newNode;
	}
};

int main() {
	return 0;
}
