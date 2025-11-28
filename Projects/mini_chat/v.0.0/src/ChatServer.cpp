#include <../include/ChatServer.h>
#include <iostream>
#include <string>
#include <thread>
#include <sys/socket.h>
#include <unistd.h>

ChatServer::ChatServer(int port) : db("chat.db") {
	db.createTable();
	
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	bind(serverSocket, (struct sockaddr*)& serverAddress, sizeof(serverAddress));	

	listen(serverSocket, 5);
}

ChatServer::~ChatServer() {}

void ChatServer::start() {
	while(true) {
		int clientSocket = accept(serverSocket, nullptr, nullptr);
		{
			std::lock_guard<std::mutex> lock(clientsMutex);
			clients.push_back(clientSocket);
		}
	
		std::string mssg = "Welcome to chat\n";
		send(clientSocket, mssg.c_str(), mssg.size(), 0);
		
		std::thread client_thread([this, clientSocket]() {
		char buffer[1024];
		while(true) {
			ssize_t bytes = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
			if(bytes <= 0) {
				close(clientSocket);
				break;
			}
			buffer[bytes] = '\0';
			std::string message(buffer, bytes);
			std::cout << message << std::endl;
			db.insertMessage(message);
			broadcast(message + "\n", clientSocket);
		}
		});
		client_thread.detach();
		
	}
}

void ChatServer::stop() {
	if(serverSocket != -1) {
		close(serverSocket);
	}
}

void ChatServer::broadcast(const std::string& message, int mySocket) {
	for(int c : clients) {
		if(c == mySocket) continue;
		send(c, message.c_str(), message.size(), 0);
	}
}
