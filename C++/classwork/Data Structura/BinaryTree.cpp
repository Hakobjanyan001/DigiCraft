#include <iostream>
#include <string>

class Tree {
//Helper Struct
private:
	struct Node{
	public:
		Node(int val) : value(val), left(nullptr), righet(nullptr) {}
	int value;
	Node* left;
	Node* righet;
	};
	
	Node* m_root;

//Helper Functions
private:

	Node* insertInner(Node* node, int val) {
		if( node == nullptr) {
			return new Node(val);
		}
		if(val < node->value ) {
			node->left = insertInner(node->left, val);
			return insertInner(node, val);
		} else {
			node->righet = insertInner(node->righet, val);
			return insertInner(node, val);
		}
		return node;
	}

//Public API
public:
	void insert(int val) {
		m_root = insertInner(m_root, val);
	}

	void inOrder(Node* node) {
	if(node == nullptr){
		return ;
	}
	inOrder(node->left);
	std::cout << node->value << std::endl;
	inOrder(node->righet);
	}	



public:
	Tree() : m_root(nullptr) {}
	~Tree() {
	while(Tree) {
	int tmp = Tree
	delete Tree->righet;
	delete Tree->left;
	Tree = tmp;
	}
	}


};

int main() {
Tree* myTree = new Tree();
myTree->insert(15);
myTree->insert(20);
myTree->insert(2);
myTree->insert(70);
myTree->insert(0);
myTree->inOrder();
	return 0;
}
