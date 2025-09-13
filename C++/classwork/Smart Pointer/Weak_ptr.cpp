#include <iostream>
#include <string>
#include <memory>

class Node{
	std::shared_ptr<Node> next;
	std::weak_ptr<Node> prev;
};

int main() {
	auto = std::make_shared<Node>(); 
	return 0;
}
