#ifndef CHATCLIENT_H
#define CHATCLIENT_H
#include <netinet/in.h>
#include <string>

class ChatClient {
private:
	std::string serverHost;
	int serverPort;
	int clientSocket;
	sockaddr_in serverAddress;

public:
	ChatClient(const std::string& host, int port);
	~ChatClient();
	void sendMessage(const std::string& msg);
	void startReceving();
};

#endif //CHATCLIENT_H
