#include <iostream>
#include <string>

/*
enum eWeekday { MON = 1, TUE, WEN, THU, FRI, SAT, SUN, UNKNOWN };

int main() {
	int iDay = 0
	while ( true ) {
			std::cout << "Enter 1-7 to get weekday\nEnter 0 to exit" << std::endl;
			std::cin >> iDay;
			eWeekday weekday = static_cast<eWeekday>(iDay);

			if ( iDay == 0) {
					std::cout << "Exiting" << std::endl;
					break;
			}

			switch( iDay ){
					case MON;
					std::cout << "Monday" << std::endl;
					break;
					default:
					std::cout << "Invalid weekday" << std::endl;
					break;
			}
	}
return 0;
}

*/

enum eHarcer { ANGL, MATEM, CRAG, };

int main() {
	std::string sPatasxan = "";
	eHarcer harcer;
	std::cout << "Patasxanir harcin vorpesi stanas 1 miavor hakarak depqum` 0\n" << std::endl;
	int iMiavor = 0;				
		for (int i = 0; i < 3; i++) {
				harcer = static_cast<eHarcer>(i);

				switch( i ){
					case ANGL:
					std::cout << "Harc Anglic: inchpes asel barev angleren : " << std::endl;
					std::cin >> sPatasxan;
					if( sPatasxan == "hello" || sPatasxan == "Hello" ) {
						iMiavor++;
						break;
					}
					case MATEM:
					std::cout << "Harc Matemic: inchi e havasar uxx. erankyan ejeri kisagumari karakusin: " << std::endl;
					std::cin >> sPatasxan;
					if( sPatasxan == "nerqnadzig" || sPatasxan == "Nerqnadzig") {
						iMiavor++;
						break;
					}
					case CRAG:
					std::cout << "Harc Crag: hishoxutyan poqraguyn miavor: " << std::endl;
					std::cin >> sPatasxan;
					if( sPatasxan == "Bayt" || sPatasxan == "bayt") {
						iMiavor++;
						break;
					}
				}
		}
		std::cout << iMiavor << "/3" << std::endl; 
return 0;
}
