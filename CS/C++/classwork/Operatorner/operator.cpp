#include <iostream>
#include <string>


class MyInt{
public:
int value;

	MyInt(int value) : value(value) {}
	MyInt(const MyInt& other) : value(value) {
		this->value = other.value;
	}
	~MyInt() {}

	MyInt operator+(const MyInt& other){
		MyInt ret;
		ret.value = value + other.value;
		return ret;	
	}


	MyInt operator-(const MyInt& other){
		MyInt ret;
		ret.value = value - other.value;
		return ret;	
	}


	MyInt operator*(const MyInt& other){
		MyInt ret;
		ret.value = value * other.value;
		return ret;	
	}


	MyInt operator/(const MyInt& other){
		MyInt ret;
		ret.value = value / other.value;
		return ret;	
	}
	MyInt& operator=(const MyInt& other){
		value = other.value;
		return *this;	
	}
	
	bool operator>(const MyInt& other){
		bool bo = false;
		if(this->value > other.value) {
			bo = true;
		}
		return bo;	
	}
	
	bool operator<(const MyInt& other){
		bool bo = false;
		if(this->value < other.value) {
			bo = true;
		}
		return bo;	
	}
	
	bool operator!=(const MyInt& other){
		bool bo = false;
		if(this->value != other.value) {
			bo = true;
		}
		return bo;	
	}

};

int main() {
	MyInt in1;
	MyInt in2;
	in1 = 2;
	in2 = 3;
	std::cout << (in1 + in2).value << std::endl;
	MyInt in3 = in1 + in2;
	std::cout << in3.value << std::endl;
	return 0;
}
