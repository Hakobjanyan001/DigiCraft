#include <../include/ChatClient.h> 
#include <iostream> 
#include <thread> 
#include <string> 

int main() {
	ChatClient client("127.0.0.1", 8080);

	std::thread recv_thred(&ChatClient::startReceving, &client);
	std::cout << "for exit write exit" << std::endl;
	
	std::string message;
	while(std::getline(std::cin, message)) {
		if(message == "exit") {
			break;
		}

		if(!message.empty()) {
			client.sendMessage(message);
		}
	}
	recv_thred.detach();
	return 0;
}
