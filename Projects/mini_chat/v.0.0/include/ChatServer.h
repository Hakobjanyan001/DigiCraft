#ifndef CHATSERVER_H
#define CHATSERVER_H
#include <netinet/in.h>
#include <string>
#include <vector>
#include <mutex>
#include <./Database.h>

class ChatServer {
private:
	int serverSocket;
	sockaddr_in serverAddress;
	Database db;
	std::vector<int> clients; 
	std::mutex clientsMutex; 
public:
	ChatServer(int port);
	~ChatServer();
	void start();
	void stop();
	void broadcast(const std::string& message, int mySocket);
};

#endif //CHATSERVER_H
