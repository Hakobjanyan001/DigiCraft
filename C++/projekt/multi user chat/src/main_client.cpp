#include <../include/ChatClient.h>
#include <iostream>
#include <thread>

int main() {
	std::string hostname = "127.0.0.1";
	int port = 8080;

	std::cout << "Welcome to Multi-User Chat\n";
	std::cout << "Write your messag\n";
	std::string username;
	std::getline(std::cin, username);

	if(username.empty()) {
		username = "No name";
	}

	ChatClient client(hostname, port, username);

	if(!client.connectToServer()) {
		std::cerr << "Can't connect in server\n";
		return 1;
	}

	client.start();
	std::cout << "connected Server\n";
	std::cout << "write message and enter Enter\n";
	std::cout << "for exit write exit\n";
	
	std::thread receiver([&client]() {
        char buffer[4096];
        while (true) {
            int bytes = recv(client.getSocketFD(), buffer, sizeof(buffer) - 1, 0);
            if (bytes <= 0) {
                std::cout << "\n[Noconnected in server\n";
                break;
            }
            buffer[bytes] = '\0';
			std::cout << buffer;    
            std::cout << "> ";      
            std::cout.flush();
        }
    });
    receiver.detach();

	std::string message;
	while(true) {
		std::getline(std::cin, message);
		if(message == "exit") {
			break;
		}
		if(!message.empty()) {
			client.sendMessage(message);
		}
	}
	
	client.disconnect();

return 0;
}
