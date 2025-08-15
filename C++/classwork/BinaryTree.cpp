#include <iostream>
#include <string>

class Tree {
//Public API
public:
	void insert(int val) {
		m_root = insertInner(m_root, val)
		insertInner();
	} 

//Helper Functions
private:
	}

	Node* insertInner(Node* node, int val) {
		if( node == nullptr) {
			return new Node(val);
		}
		if(val < node->val ) {
			node->left = insertInner(node->left, val);
			return insertInner(node, val);
		} else {
			node->righet = insertInner(node->righet, val);
			return insertInner(node, val);
		}
		return node;
	}

//Helper Struct
private:
	Node* m_root;
	struct Node{
	private:
		node(int val) : value(val), left(nullptr), righet(nullptr) {}
	int value;
	Node* left;
	Node* righet;
	};
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
	return 0;
}
