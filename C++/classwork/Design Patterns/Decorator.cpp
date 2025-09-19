#include <iostream>
#include <string>
#include <memory>

class Coffee {
public:
	virtual std::string description() = 0;
	virtual int cost() = 0;
};

class SimpleCoffee : public Coffee {
public:
	virtual std::string description() override{
		return  "Simple Coffee";
	}

	virtual int cost() override { return 600; };
};

class CoffeeDecorator : public Coffee {
protected:
	std::unique_ptr<Coffee> coffee;
public:
	CoffeeDecorator(std::unique_ptr<Coffee> type) : coffee(std::move(type)) {};
};

class Milk : public CoffeeDecorator {
public:
	Milk(std::unique_ptr<Coffee> type) : CoffeeDecorator(std::move(type)) {};
	virtual std::string description() override{
		return coffee->description() + " + Milk";
	}

	virtual int cost() override {return coffee->cost() + 200; };
};

class Sugar : public CoffeeDecorator {
public:
	Sugar(std::unique_ptr<Coffee> type) : CoffeeDecorator(std::move(type)) {};
	virtual std::string description() override{
		return coffee->description() + " + Sugar";
	}

	virtual int cost() override {return coffee->cost() + 200; };
};


int main() {
	std::unique_ptr<Coffee> coffee1 = std::make_unique<SimpleCoffee>();
	coffee1 = std::make_unique<Milk>(std::move(coffee1));
	coffee1 = std::make_unique<Sugar>(std::move(coffee1));
	std::cout << coffee1->description() << std::endl;
	std::cout << coffee1->cost() << "\n" << std::endl;
	
	std::unique_ptr<Coffee> coffee2 = std::make_unique<SimpleCoffee>();
	coffee2 = std::make_unique<Milk>(std::move(coffee2));
	std::cout << coffee2->description() << std::endl;
	std::cout << coffee2->cost() << std::endl;
return 0;
}
