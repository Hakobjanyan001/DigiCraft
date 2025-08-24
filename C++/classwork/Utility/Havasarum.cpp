#include <iostream>
#include <string>


class Havasarum{

//Public API
	public:

	void insert(int prefex, int exp){
		if(prefex == 0){
			return;
		}
		Node* newNode = new Node( prefex, exp );
		newNode->m_next = m_head;
		m_head = newNode;
	}

	void display() {
		if ( m_head == nullptr ) {
			std::cout << 0 << std::endl;
			return;
		}
		Node* curr = m_head;
		while( curr != nullptr ) {
			std::cout << curr->m_prefex << "x^" << curr->m_exp;
			if( curr->m_next != nullptr ) {
			std::cout << "+";
			}
			curr = curr->m_next;
		}
		std::cout << "" << std::endl;
	}


	int evaluate(int value){
		if ( m_head == nullptr ) {
			return 0;
		}
		int sum = 0;
		Node* curr = m_head;
		while( curr != nullptr ) {
			sum += curr->m_prefex * expponent(value, curr->m_exp);
			curr = curr->m_next;
		}
		return sum;
	}

	
	Havasarum* add(const Havasarum& extFract) {
		Havasarum* res = new Havasarum();
		Node* curr1 = m_head;
		Node* curr2 = extFract.m_head;

		while( curr1 != nullptr || curr2 != nullptr ){
			int prefex = 0;
			int exp = 0;

			if(curr1 != nullptr && curr2 != nullptr) {
				if(curr1->m_exp == curr2->m_exp){
					prefex = curr1->m_prefex + curr2->m_prefex;
					exp = curr1->m_exp;
					curr1 = curr1->m_next;
					curr2 = curr2->m_next;
				} else if (curr1->m_exp > curr2->m_exp) {
					prefex = curr1->m_prefex;
					exp = curr1->m_exp;
					curr1 = curr1->m_next;
				} else {
					prefex = curr2->m_prefex;
					exp = curr2->m_exp;
					curr2 = curr2->m_next;
				}	
				if(prefex != 0) {
	       				res->insert(prefex, exp);	
				}
			} else if(curr1 != nullptr) {
				prefex = curr1->m_prefex;
				exp = curr1->m_exp;
				curr1 = curr1->m_next;
			} else {
				prefex = curr2->m_prefex;
				exp = curr2->m_exp;
				curr2 = curr2->m_next;
			}
		}
	        return res;
	}
	

//Helper Functions
private:
	int expponent(int base, int exp) {
		if( exp == 0 ) { return 1; }
		int sum = 1;
		for(int i = 0; i < exp; i++ ){
			sum *= base;
		}
		return sum;
	}
	
//Struct Node
private:	
struct Node {
	//Member data
	public:
		Node* m_next;
		int m_prefex;
		int m_exp;
	//Ctr / Dtr
	public:
	Node(int prefex, int exp) :
 		m_next(nullptr), 
		m_prefex(prefex), 
		m_exp(exp) {}
	~Node() {}
	
	//Geter
	int getPrefex() { return m_prefex; }
	int getExp() { return m_exp; }
	
};
private:
Node* m_head;
	
};

int main() {
	Havasarum* ha = new Havasarum();
	ha->insert(2, 4);
	ha->insert(3, 2);
	ha->display();

	Havasarum* ha2 = new Havasarum();
	ha2->insert(1, 3);
	ha2->insert(4, 2);
	ha2->display();

	Havasarum* ha3 = ha->add(*ha2);
	ha3->display();

	std::cout << ha->evaluate(3) << std::endl;
	return 0;
}
