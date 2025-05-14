#include <iostream>
#include <string>


struct usanox {
std::string Name;
std::string Surname;
};

struct xumb {
	std::string anun; //011b
	usanox usanox1;
	usanox usanox2;
	usanox usanox3;
	usanox usanox4;
	usanox usanox5;
};

struct bajin {
	xumb Vaqsh_011b; // Vaqsh_011b
	std::string anun; // Magistros_1in
};

struct ambion {
	std::string anun; // Shinarar
	bajin Vaqsh; //Vaqsh
};

struct hamalsaran{
	std::string anun; // HAPH
	std::string qaxaq; // Vanadzor
	ambion Shinarar; //Shinararakan
};

int main() {
	usanox xumbi_usanox;
	xumbi_usanox.Name = "Karen";
	xumbi_usanox.Surname = "Hakobjanyan";
	std::cout << "Name: " << xumbi_usanox.Name << std::endl;
	std::cout << "Surname: " << xumbi_usanox.Surname << "\n" << std::endl;

	xumb bajini_xumb;
	bajini_xumb.anun = "011b";
	bajini_xumb.usanox = 
	bajini_xumb.Seyran;
	bajini_xumb.Mariam;
	bajini_xumb.Meri;
	bajini_xumb.Lusine;
	std::cout << "xumbi anun: " << bajini_xumb.anun << "\n" << std::endl;


	bajin ambioni_bajin;
	ambioni_bajin.anun = "Magistros_1in";
	ambioni_bajin.Vaqsh_011b;
	std::cout << "Bajini anun: " << ambioni_bajin.anun << "\n" << std::endl;

	ambion hamalsarani_ambion;
	hamalsarani_ambion.anun = "Shinarar";
	hamalsarani_ambion.Vaqsh;
	std::cout << "Ambioni anun: " << hamalsarani_ambion.anun << "\n" << std::endl;

	hamalsaran poloi_hamalsaran;
	poloi_hamalsaran.anun = "HAPH";
	poloi_hamalsaran.qaxaq = "Vanadzor";
	poloi_hamalsaran.Shinarar;
	std::cout << "Hamalsarani anun: " << poloi_hamalsaran.anun << std::endl;
	std::cout << "Hamalsarani qaxaqy: " << poloi_hamalsaran.qaxaq << std::endl;

	return 0;
}
