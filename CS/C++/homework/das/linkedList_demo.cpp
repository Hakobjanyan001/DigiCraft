#include<iostream>
#include<string>

template <typename T>
class myList : public std::exception {
private:
	struct Node {
	public:
		T m_data;
		Node* m_next;
	
	Node(T val) : m_data(val), m_next(nullptr) {}
	~Node() {}
	};

private:
Node* m_head;
int m_size;

public:
	myList() : m_head(nullptr), m_size(0) {}
	~myList() {
		while(m_head) {
			Node* tmp = m_head; 
			m_head = m_head->m_next;
			delete tmp;
		}
	}

	void push_back(T val) {
		Node* newNode = new Node(val);
		if(!m_head) { 
			m_head = newNode;
		}else {
			Node* curr = m_head;
			while(curr->m_next) {
				curr = curr->m_next;
			}
			curr->m_next = newNode;
		}
		m_size++;
	}
	
	void pop_back() {
		if(!m_head) {return;}
		
		if(!m_head->m_next) {
			delete m_head;
			m_head = nullptr;	
		} else {
			Node* curr = m_head->m_next;
			while(curr->m_next) {
				curr = curr->m_next;
			}
			delete curr->m_next;
			curr->m_next = nullptr;
		}
		m_size--;
	}

	int size() {return m_size;}

	T at(int index) {
		try {
			if(index >= 0 && index < m_size) {
				Node* curr = m_head;
				for(int i = 0; i < index; i++) {
					curr = curr->m_next;
				}
				return curr->m_data;
			}
			throw new myList();
		}catch(const std::exception* e){
			std::cerr << "Error: " << e->what() << std::endl;
			return -1;
		}
	}

};

int main() {
myList<int>* list = new myList<int>();
list->push_back(2);
list->push_back(4);
list->push_back(7);
std::cout << "size " << list->size() << std::endl;
list->pop_back();
std::cout << "size " << list->size() << std::endl;
std::cout << "at 1 " << list->at(0) << std::endl;
std::cout << "at 2 " << list->at(1) << std::endl;
return 0;
}
