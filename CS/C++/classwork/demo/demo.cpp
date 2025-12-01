#include <iostream>

class Tree {
struct Node;
public:
	Tree() : m_root(nullptr) {}
	~Tree() {
		deleteNode(m_root);
	}

	void deleteNode(Node* node) {
		if(node == nullptr) {
			return;
		}
		deleteNode(node->m_left);
		deleteNode(node->m_right);
		delete node;
	}

	void insert(int val) {
		m_root = insertInner(m_root, val);
	}

	void preorder() {
		preorder(m_root);
	}

	void inorder() {
		inorder(m_root);
	}

	void postorder(){
		postorder(m_root);
	}

private:
	struct Node {
		Node* m_left;
		Node* m_right;
		int m_value;
	
		Node(int val) : m_left(nullptr), m_right(nullptr), m_value(val) {}
		~Node() {}
	};

	Node* m_root;

	Node* insertInner(Node* node, int val) {
		if(node == nullptr) {
			return new Node(val);
		}
		
		if(val < node->m_value) {
			node->m_left = insertInner(node->m_left, val);
		}

		if(val > node->m_value) {
			node->m_right = insertInner(node->m_right, val);
		}
		return node;
	}

	void preorder(Node* node) {
		if(node == nullptr) {
			return;
		}

		std::cout << node->m_value << std::endl;
		preorder(node->m_left);
		preorder(node->m_right);
	}

	void inorder(Node* node) {
		if(node == nullptr) {
			return;
		}

		inorder(node->m_left);
		std::cout << node->m_value << std::endl;
		inorder(node->m_right);
	}

	void postorder(Node* node) {
		if(node == nullptr) {
			return;
		}
		
		postorder(node->m_left);
		postorder(node->m_right);
		std::cout << node->m_value << std::endl;
	}

};

int main() {
	Tree* tree = new Tree();
	tree->insert(5);
	tree->insert(2);
	tree->insert(8);
	tree->insert(9);
	tree->insert(4);
	tree->preorder();
	std::cout << "\n";
	tree->inorder();
	std::cout << "\n";
	tree->postorder();
return 0;
}
