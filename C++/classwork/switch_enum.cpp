#include <iostream>
#include <string>

enum errors {
	NOTFOUND,
	SUCCESS,
	UNKNOWN
};

int main() {
enum errors error = NOTFOUND;
switch (error) {
	case NOTFOUND:
		std::cout << "Error 404" << std::endl;
		break;
	case SUCCESS:
		std::cout << "Error 200" << std::endl;
		break;
	default UNKNOWN:
		std::cout << "Unknown" << std::endl;
		break;
}

}
