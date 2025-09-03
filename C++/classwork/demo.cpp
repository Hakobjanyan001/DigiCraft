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


//_____________________________________________________________________________

/*
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
	
}
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
*/

//_______________________________________________________________________________________

/*
void calculateStats(int arr[]);

int main() {
	int arr[5] = {7, 5, 6, 9, 4};
	calculateStats(arr);
	return 0;
}

void calculateStats(int arr[]) {
	int sum = 0;
	for (int i = 0; i < 5 ; i++) {
		sum += arr[i];
	}
	float mij = sum / 5.0f;
	std::cout << "mijin =" << mij << std::endl;
	
	int max = arr[0];
	for(int i = 0; i < 5; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	std::cout << "arr[max] = " << max << std::endl;
}
*/



// _____________________________________________________________________________

/*
class Matrix{
//Member Data
private:
	int tox;
	int syun;
	int** Arr;

// Ctor / Dtor
public:
	Matrix(int extSyun, int extTox) : syun(extSyun), tox(extTox){
		Arr = new int* [syun] ;
		for(int i = 0; i < syun; i++) { 
			Arr[i] = new int [tox];
			for(int j = 0; j < tox; j++) {
				Arr[i][j] = 0;
			}	
		}
	}
	~Matrix() {
		
		for(int i = 0; i < syun; i++) { 
				delete [] Arr[i];
		}	
		delete [] Arr;
		
	}


	void setData(int extSyun, int extTox, int value) {
		if(extSyun > 0 && extSyun < syun && extTox > 0 && extTox < tox){
			Arr[extSyun][extTox] = value;
		}
	}

	int getData(int extSyun, int extTox) {
		if(extSyun > 0 && extSyun < syun && extTox > 0 && extTox < tox){
			return Arr[extSyun][extTox];
		}
		return 0;
	}

	Matrix add(const Matrix& extMX){
		if(syun == extMX.syun && tox == extMX.tox){
			Matrix res(syun, tox);
			for(int i = 0; i < syun; i++){
				for(int j = 0; j < tox; j++){
					res.Arr[i][j] = Arr[i][j] + extMX.Arr[i][j];
				}	
			}
			return res;
		}
		return Matrix(0, 0);
	}

	
	Matrix multiply(const Matrix& extMX){
		if(syun == extMX.syun && tox == extMX.tox){
			Matrix res(syun, tox);
			for(int i = 0; i < syun; i++){
				for(int j = 0; j < tox; j++){
					res.Arr[i][j] = Arr[i][j] * extMX.Arr[i][j];
				}	
			}
			return res;
		}
		return Matrix(0, 0);
	}
	
	
	
	void display() {
		for(int i = 0; i < syun; i++){
			for(int j = 0; j < tox; j++){
				std::cout << Arr[i][j] << " ";
			}
			std::cout << std::endl;	
		}
	}


};



int main() {
	Matrix* mx1 = new Matrix(3, 3);
	mx1->setData(2, 2, 7);
	
	Matrix* mx2 = new Matrix(3, 3);
	mx2->setData(2, 1, 5);

	Matrix mx3 = mx1->add(*mx2);
	Matrix mx4 = mx1->multiply(*mx2);
	
	std::cout << "Matrix 1:" << std::endl;
	mx1->display();

	delete mx1;
	delete mx2;
	return 0;
}

template <typename T> 
class Var {
	public:
	T value;
	void print() {
		std::cout << value << std::endl;
	}
};


template <typename T>
T add(T a, T b){
	return a + b;
}

template <typename T, typename T2>
T add(T a, T2 b){
	return a + b;
}

int main() {
	Var<int> myVar;
	// Var* myvar = new Var<int>(); heap->i mej
	myVar.value = 24;
	myVar.print();
	
	std::cout << add<T>(7, 9)<< std::endl;
	std::cout << add<T, T2>(8, true)<< std::endl;
	return 0;
}
*/


template <typename T>
class Ban{
	public:
	T lvalue;
	T rvalue;
	
	Ban(T a, T b) : lvalue(a), rvalue(b) {}
	~Ban() {}
	
	Ban min(T lvalue, T rvalue){
		if(lvalue > rvalue){
			return rvalue;
		}
		return lvalue;
	}
	

	Ban max(T lvalue, T rvalue){
		if(lvalue < rvalue){
			return rvalue;
		}
		return lvalue;
	}


};
