 #include <iostream>
 #include <string>
 
void printBoard(char board[3][3]);
 
bool tuylatrvume(int, int, char boar[3][3]);

const char xPlayer = 'x';
const char oPlayer = 'o';
char empty = ' ';  // empty in probelna

bool haxtec(char, char board[3][3]);

bool avart (char, char board[3][3]);

int main() {
 
    char player = xPlayer;
 
    char board[3][3] = {
        {empty, empty, empty},
        {empty, empty, empty}, 
 		{empty, empty, empty}
    };
 
    int tox = 0;
    int syun = 0;
    while(true) {
        std::cout << player << ": tur tox: "<< std::endl;
        std::cin >> tox;
 
        std::cout << player << ": tur syun: "<< std::endl;
        std::cin >> syun;

	 if (tuylatrvume(tox, syun, board) == false) {
		 std::cout << "voch tuylatreli qayl, duq partveleq" << std::endl;
		break;
	}
        board[tox][syun] = player;
 
        printBoard(board);
 		
		if (haxtec(player, board)) {
			std::cout << "Player " << player  << " haxtec" << std::endl;
			break;
		}
		
		if (avart(player, board)) {
			std::cout << "xaxy avartvel e nichya" << std::endl;
			break;
		}

        if (player == xPlayer){
            player = oPlayer;
        } else {
            player = xPlayer;
        }
    }
 
    return 0;
}
 
 
void printBoard(char board[3][3]){
     std::cout << board[0][0] << " | " << board[0][1] << " | " <<  board[0][2] <<  std::endl;
     std::cout << "--+--+--+" << std::endl;
     std::cout << board[1][0] << " | " << board[1][1] << " | " <<  board[1][2] <<  std::endl;
     std::cout << "--+--+--+" << std::endl;
     std::cout << board[2][0] << " | " << board[2][1] << " | " <<  board[2][2] <<  std::endl;
     std::cout << "--+--+--+" << std::endl;
 }

bool tuylatrvume(int tox, int syun, char board[3][3]) {
	return tox >= 0 && tox <= 2 && syun >= 0 && syun <= 2 && board[tox][syun] == empty;
}

bool haxtec(char player, char board[3][3]) {
	// yst toxeri
	if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
		return true;
	}
		
	if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
		return true;
	}
	
	if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
		return true;
	}
	// yst syuneri
	if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
		return true;
	}
	if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
		return true;
	}
	if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
		return true;
	}
	// yst ankyunagceri
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return true;
	}
	if (board[0][0] == player && board[1][1] == player && board[2][0] == player) {
		return true;
	}

	return false;
}

bool avart (char, char board[3][3]) {
	for(int i = 0; i < 3; i++) {
			for(int z = 0; z < 3; z++) {
				if(board[i][z] == empty) {
					return false;
				}
			}
	}
	return true;
}
