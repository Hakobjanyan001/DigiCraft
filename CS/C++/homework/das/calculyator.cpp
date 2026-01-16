#include<iostream>

class Calculyator {
private:
	double m_number1;
	double m_number2;
	char m_operation;
	
	double calculate(double& a, char& op, double& b) {
		switch(op) {
			case '+':
				return a + b;
	
			case '-':
				return a - b;
		
			case '*':
				return a * b;

			case '/':
				if(b != 0) {
					return a / b;
				} else {
					std::cerr << "Error: Division by zero\n";
					return 0;
				}
			
			default :
				std::cerr << "Unknown operation\n";
				return 0;
		}
	}
public:
	Calculyator(double number1, char operation, double number2) : 
			m_number1(number1),
	   		m_operation(operation),
			m_number2(number2) {}
	~Calculyator() {}

// public API 
public:
	void show() {
		std::cout << m_number1 << " " << m_operation << " " << m_number2 << " = "; 
		double result = calculate(m_number1,m_operation,m_number2);
		std::cout << result << std::endl;
	}

	double getResult() {
		return calculate(m_number1, m_operation, m_number2);
	}

};

int main() {
	Calculyator* ct = new Calculyator(15,'*',10);
	ct->show();
	delete ct;
	return 0;
};
