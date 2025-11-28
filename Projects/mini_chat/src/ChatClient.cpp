#include <../include/ChatClient.h>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <string>

ChatClient::ChatClient(const std::string& host, int port) : 
		serverHost(host),
		serverPort(port) {	
	
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	
	if(connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
		std::cerr << "Disconnected server" << std::endl;
	};
}

ChatClient::~ChatClient() {
	close(clientSocket);
}

void ChatClient::sendMessage(const std::string& message) {
	
	send(clientSocket, message.c_str(), message.size(), 0);
}

void ChatClient::startReceving() {
	char buffer[4096];
	while(true){
		int bytes = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
		if(bytes <= 0) {
			std::cout << "Disconnected server" << std::endl;
			break;
		}
	buffer[bytes] = '\0';
	std::cout << buffer;
	}
}
