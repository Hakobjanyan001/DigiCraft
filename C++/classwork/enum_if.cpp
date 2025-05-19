#include <iostream>
#include <string>

/*
enum zangeri_kentron {
	HASHVAPAHUTYUN,
	VACHARQ,
	TNOREN,
	HR,
	SRAH,
	ARAQUM,
	OPERATOR,
	UNKNOWN
};

int main() {
enum zangeri_kentron zang = HASHVAPAHUTYUN;
switch (zang) {
	case HASHVAPAHUTYUN:
		std::cout << "kap Hashvaoahutyun" << std::endl;
		break;
	case VACHARQ:
		std::cout << "kap VACHARQ" << std::endl;
		break;
	case TNOREN:
		std::cout << "kap Tnoreni het" << std::endl;
		break;
	case HR:
		std::cout << "kap HR" << std::endl;
		break;
	case SRAH:
		std::cout << "kap Srah" << std::endl;
		break;
	case ARAQUM:
		std::cout << "kap Araqum" << std::endl;
		break;
	case OPERATOR:
		std::cout << "kap Operatorin" << std::endl;
		break;
	default:
		std::cout << "sxal argument" << std::endl;
		break;
}

}





int main() {
int num = 0;
std::cout << "greq argument 1-ic minchev 7: ";
std::cin >> num ;
switch (num) {
	case 1:
		std::cout << "kap Hashvapahutyun" << std::endl;
		break;
	case 2:
		std::cout << "kap Vacharq" << std::endl;
		break;
	case 3:
		std::cout << "kap Tnoren" << std::endl;
		break;
	case 4:
		std::cout << "kap HR" << std::endl;
		break;
	case 5:
		std::cout << "kap Srah" << std::endl;
		break;
	case 6:
		std::cout << "kap Araqum" << std::endl;
		break;
	case 7:
		std::cout << "kap Operator" << std::endl;
		break;
	default:
		std::cout << "sxal argument" << std::endl;
		break;
}
}

*/

enum argument {
	GUMARUM,
	HANUM,
	BAJANUM,
	BAZMAPATKUM
};

int main() {
int num1 = 0;
int num2 = 0;
std::cout << "grir 1in arjeqy: ";
std::cin >> num1;
std::cout << "grir 2-rd arjeqy: ";
std::cin >> num2;
std::cout << "gri gorcoxutyun: ";
std::string nshan;
std::cin >> nshan;

if( nshan == "+" ) {
enum argument arg = GUMARUM;
switch (arg) {
	case GUMARUM:
		std::cout << "gumarumy: " << num1 + num2 << std::endl;
		break;
}
}
if( nshan == "-" ) {
enum argument arg = HANUM;
switch (arg) {
	case HANUM:
		std::cout << "Hanumy: " << num1 - num2 << std::endl;
		break;
}
} 
if( nshan == "/" ) {
enum argument arg = BAJANUM;
switch (arg) {
	case BAJANUM:
		std::cout << "Bajanum: " << num1 / num2 << std::endl;
		break;
}
}
if( nshan == "*" ) {
enum argument arg = BAZMAPATKUM;
switch (arg) {
	case BAZMAPATKUM:
		std::cout << "Bazmapatkum: " << num1 * num2 << std::endl;
		break;
	default:
		std::cout << "Sxal argument " << std::endl;
		break;
}
}
}
