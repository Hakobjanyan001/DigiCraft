#include <iostream>
#include <string>

class vector{
	protected:
	int capacity;
	int size;
	int* arr;
	public:
	vector() :  size(0)
				capacity(0)
				arr(nullptr)
	{
	
	};

	~vector(){
		delete[] arr;
	};


	void push_back(int e){
		for(int i = 0; i <= size; i++){
			if(size = 0){
				size += 1;
				vector[element];
			}else if(size > i) {
				vector[element]
				} else {
					size * 2;
					vector[element];
					}
				}
	}
	
	int pop_back();

	
};

int main(){
vector* v = new vector(size);
v->push_back(20);
return 0;
}
