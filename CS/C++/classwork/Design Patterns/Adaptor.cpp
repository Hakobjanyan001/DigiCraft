#include <iostream>
#include <string>
#include <memory>


class Player {
public:
	virtual void play(std::string song) = 0;
};

class mp3Player {
public:
	void playmp3(std::string song) {
		std::cout << "Playing: " << song << std::endl;
	}
};

class PlayerAdapter : public Player {
private:
	mp3Player player;
public:
	void play(std::string song) override {
		player.playmp3(song);
	}
};

int main() {
	Player* p = new PlayerAdapter();
	p->play("MyFavoritSong.mp3");
return 0;
}
