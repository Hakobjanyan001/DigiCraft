#include <iostream>
#include <string>

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
