#include<iostream>
#include<string>

class Tree {
	struct Node;	
public:
	Tree() : m_root(nullptr) {}
	~Tree() {
		deleteNode(m_root);
	}
	
	void deleteNode(Node* node) {
		if( node == nullptr ) { return; }
		deleteNode(node->m_left);
		deleteNode(node->m_right);
		delete node;
	}

	void insert(int val) {
		m_root = insertInner(m_root, val);
	}	

	Node* insertInner(Node* node, int val) {
		if( node == nullptr) { return new Node(val); }
		if( val < node->m_value ) { 
			node->m_left = insertInner(node->m_left, val);  
		} else if ( val > node->m_value ) { 
			node->m_right = insertInner(node->m_right, val); 
		}
		return node;
	}

	void preOrder() {
		preOrder(m_root);
	}

	void inOrder() {
		inOrder(m_root);
	}	

	void postOrder() {
		postOrder(m_root);
	}

	void preOrder(Node* node) {
		if( node == nullptr ) { return; } 
		std::cout << node->m_value << std::endl;
		preOrder(node->m_left);
		preOrder(node->m_right);
	}

	void inOrder(Node* node) {
		if( node == nullptr ) { return; } 
		inOrder(node->m_left);
		std::cout << node->m_value << std::endl;
		inOrder(node->m_right);
	}	

	void postOrder(Node* node) {
		if( node == nullptr ) { return; } 
		postOrder(node->m_left);
		postOrder(node->m_right);
		std::cout << node->m_value << std::endl;
	}
private:
	struct Node {
		int m_value;
		Node* m_left;
		Node* m_right;

		Node(int val) : m_value(val), m_left(nullptr), m_right(nullptr) {}
	};

private:
	Node* m_root;
};

int main() {
	Tree* myTree = new Tree();
	myTree->insert(12);
	myTree->insert(15);
	myTree->insert(20);
	myTree->insert(3);
	myTree->insert(2);
	myTree->insert(1);
	myTree->insert(8);
	myTree->insert(6);
	myTree->insert(13);
	myTree->preOrder(); 
	myTree->inOrder();
	myTree->postOrder();
return 0;
}
