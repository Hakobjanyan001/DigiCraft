#ifndef CHATSERVER_H
#define CHATSERVER_H

#include<Database.h>
#include<User.h>
#include<unistd.h>
#include<vector>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<thread>
#include<mutex>

struct Client {
	int socket;
	User user;
	bool authenticated;
	std::thread thread;

	Client(int sock) : socket(sock), user(), authenticated(false) {}
	~Client() {
		if(thread.joinable()) {
			thread.join();
		}
		if(socket != -1) {
			close(socket);
			socket = -1;
		}
	}
};

class ChatServer {
private:
	int server_socket;
	int port;
	bool running;
	std::vector<Client*> clients;
	Database db;
	std::mutex clients_mutex;

	void acceptClients();
	void handleClient(Client* client);
	void removeClient(Client* client);
	void cleanup();

public:
	ChatServer(int p = 8080);
	~ChatServer();

	bool start();
	void stop();
	void broadcast(const std::string& message, int exclude_fd);
};

#endif // CHATSERVER_H
