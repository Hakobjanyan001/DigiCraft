#include <iostream>
#include <string>
class Kotorak {
//Member data
private:
	int m_hamarich;
	int m_haytarar;
//Helper Funkction
private:
	int GCD(int m_hamarich, int haytarar){
	}

//Ctrd / Dtr 	
public:
	Kotorak(int hamarich, int haytarar,) : 
		m_hamarich(hamarich = 0), 
		m_haytarar(haytarar = 0){
			GCD(m_hamarich, m_haytarar);
		}
	~Kotorak() {}
// geter/seter
public:
	void setHamarich(int hamarich) { m_hamarich = hamarich; }
	int getHamarich() { return m_hamarich; }
	
	void setHaytarar(int haytarar) { m_haytarar = haytarar; };
	int getHaytarar() { return m_haytarar; }
//Public API
public:
	int ham, hayt;
	Kotorak* add(const Kotorak& extFract,){
		hayt = m_haytarar * extFract->getHamarich();
		ham = ((hayt / m_haytarar) * m_hamarich) + ((hayt / extFract->getHaytarar()) * extFract->getHamarich());
		return new Kotorak(ham, hayt);
	}
	}
	
//Helper Funkcion
public:
	int GSD(const Kotorak& m_haytarar, const Kotorak& extFract->m_haytarar ){
	if(m_haytarar >= extFract->m_haytarar) ? 
	}

};


int main() {
Kotorak* ko1 = new Kotorak(1, 2);
Kotorak* ko2 = new Kotorak(2, 4);
Kotorak* ko3 = ko1->add(ko2);
	return 0;
}
