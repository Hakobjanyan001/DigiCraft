#include <iostream>
#include <string>

/*
class Kotorak {
//Member data
private:
	int m_hamarich;
	int m_haytarar;
//Helper Funkction
private:
	int GCD(int a, int b){
		int tmp;
		while( b != 0){
			tmp = b;
			b = a % b;
			a = tmp;
		}
	       	return a;
	}


//Ctrd / Dtr 	
public:
	Kotorak(int hamarich = 0, int haytarar = 1) : 
		m_hamarich(hamarich), 
		m_haytarar(haytarar){	
			if(m_haytarar == 0 && m_hamarich != 0){
				std::cout << "haytarary chi karox 0 linel" << std::endl;
				m_haytarar = 1;
			}
			int gcd = GCD(m_hamarich, m_haytarar);
			m_hamarich /= gcd;
			m_haytarar /= gcd;
		}

	~Kotorak() {
		}
// geter/seter
public:
	void setHamarich(int hamarich) { m_hamarich = hamarich; }
	int getHamarich() const { return m_hamarich; }
	
	void setHaytarar(int haytarar)  { m_haytarar = haytarar; };
	int getHaytarar() const { return m_haytarar; }

//Public API
public:
	Kotorak* add(const Kotorak& extFract){
		int hayt = getHaytarar() * extFract.getHaytarar();
		int ham = ((hayt / getHaytarar()) * getHamarich()) + ((hayt / extFract.getHaytarar()) * extFract.getHamarich());
		return new Kotorak(ham, hayt);
	}
	
	
	Kotorak* removal(const Kotorak extFract) {
		int hayt = getHaytarar() * extFract.getHaytarar();
		int ham = ((hayt / getHaytarar()) * getHamarich()) - ((hayt / extFract.getHaytarar()) * extFract.getHamarich());
		if(getHaytarar() > extFract.getHaytarar()) {
		return new Kotorak(ham, hayt);
		}
		
		return new Kotorak(-ham, hayt);
	}

	
	Kotorak* division(const Kotorak& extFract){
	int ham = getHamarich() * extFract.getHaytarar();
	int hayt = getHaytarar() * extFract.getHamarich();
	return new Kotorak(ham, hayt);	
	}
	
	
	Kotorak* multiplication(const Kotorak& extFract){
	int ham = getHamarich() * extFract.getHamarich();
	int hayt = getHaytarar() * extFract.getHaytarar();
	return new Kotorak(ham, hayt);	
	}


};

int main() {
Kotorak* ko1 = new Kotorak(1, 2);
Kotorak* ko2 = new Kotorak(2, 4);
Kotorak* ko3 = ko1->add(*ko2);
std::cout << ko3->getHamarich() << "\n-\n" << ko3->getHaytarar() << "\n" << std::endl;

Kotorak* ko4 = ko1->removal(*ko2);
std::cout << ko4->getHamarich() << "\n-\n" << ko3->getHaytarar() << "\n" << std::endl;

Kotorak* ko5 = ko1->division(*ko2);
std::cout << ko5->getHamarich() << "\n-\n" << ko5->getHaytarar() << "\n" << std::endl;

Kotorak* ko6 = ko1->multiplication(*ko2);
std::cout << ko6->getHamarich() << "\n-\n" << ko6->getHaytarar() << std::endl;

delete ko1;
delete ko2;
delete ko3;
delete ko4;
delete ko5;
delete ko6;
	return 0;
}
*/

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
			sum += curr->m_prefex + expponent(value, curr->m_exp);
			curr = curr->m_next;
		}
		return sum;
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
	~Node() {
			while( m_head != nullptr ){
				Node* tmp = m_head;
				m_head = m_head->m_next;
				delete m_head;
			}
		}
	
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
	std::cout << ha->evaluate(3) << std::endl;
	return 0;
}
