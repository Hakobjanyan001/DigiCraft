#include <iostream>
#include <string>

class Tree {
struct Node;

//Public API
public:
	Tree() : m_root(nullptr) {}
	~Tree() {
		deleteNode(m_root);
		}

	void deleteNode(Node* node) {
	if(node == nullptr){
		return;
	}
	deleteNode(node->left);
	deleteNode(node->righet);
	}

	
	void insert(int val) {
		m_root = insertInner(m_root, val);
	}

	void preOrder(){
		preOrder(m_root);
	}

	void inOrder(){
		inOrder(m_root);
	}
	
	void postOrder(){
		postOrder(m_root);
	}

//Helper Functions
private:

	Node* insertInner(Node* node, int val) {
		if( node == nullptr) {
			return new Node(val);
		}
		if(val < node->value ) {
			node->left = insertInner(node->left, val);
		} else {
			node->righet = insertInner(node->righet, val);
		}
		return node;
	}

	void preOrder(Node* node) {
	if( node == nullptr) {
		return;
	} 
		std::cout << node->value << std::endl;
		preOrder(node->left);
		preOrder(node->righet);
	}
	
	void inOrder(Node* node) {
	if( node == nullptr) {
		return;
	} 
		inOrder(node->left);
		std::cout << node->value << std::endl;
		inOrder(node->righet);
	}

	void postOrder(Node* node) {
	if( node == nullptr) {
		return;
	} 
		postOrder(node->left);
		postOrder(node->righet);
		std::cout << node->value << std::endl;	
	}

//Helper Struct
private:
	struct Node{
	public:
		Node(int val) : value(val), left(nullptr), righet(nullptr) {}
	int value;
	Node* left;
	Node* righet;
	};
	
//Member Data
	Node* m_root;

};

int main() {
Tree* myTree = new Tree();
myTree->insert(15);
myTree->insert(20);
myTree->insert(2);
myTree->insert(70);
myTree->insert(6);
myTree->preOrder();
std::cout << "" << std::endl;
myTree->inOrder();
std::cout << "" << std::endl;
myTree->postOrder();
	return 0;
}
