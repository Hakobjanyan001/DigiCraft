#ifndef CHATCLIENT_H
#define CHATCLIENT_H
#include <thread>
#include <string>
#include <arpa/inet.h>
#include <atomic>

class ChatClient {
private:
	std::string hostname;
	std::string username;
	int port;
	int socket_fd = -1;
	struct sockaddr_in server_addr;
	std::atomic<bool> running{false};
	std::thread receive_thread;
	void receiveMessages();
	
public:
	ChatClient(const std::string& host, int p, const std::string& name);
	~ChatClient();
	bool connectToServer();
	void disconnect();
	bool sendMessage(const std::string& message);
	void startReceiving();
	bool isConnected() const;
	void start();
	const std::string& getUsername() const;
	int getSocketFD() {return socket_fd;}

};

#endif //CHATCLIENT_H
