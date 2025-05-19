#include <iostream>
#include <string>


struct usanox {
std::string name;
std::string surname;
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
	xumb vaqsh_011b; // Vaqsh_011b
	std::string anun; // Magistros_1in
};

struct ambion {
	std::string anun; // Shinarar
	bajin Vaqsh; //Vaqsh
};

struct hamalsaran{
	std::string anun; // HAPH
	std::string qaxaq; // Vanadzor
	ambion Shinararakan; //Shinararakan
};

int main() {
	hamalsaran polo;
	ambion shinarar;
	bajin vaqsh;
	xumb imxumb;
	usanox karen;
	usanox meri;
	usanox erik;
	usanox gor;
	karen.name = "Karen";
	karen.surname = "Hakobjanyan";
	meri.name = "Meri";
	meri.surname = "Asryan";
	erik.name = "Erik";
	erik.surname = "Khachatryan";
	gor.name = "Gor";
	gor.surname = "Grigoryan";
	vaqsh.anun = "Magistarura_1in";
	vaqsh.vaqsh_011b = imxumb; 
	imxumb.anun = "011b";
	imxumb.usanox1 = karen;
	imxumb.usanox2 = meri;
	imxumb.usanox3 = erik;
	imxumb.usanox4 = gor;
	return 0;
}
