#ifndef CHATSERVER_H
#define CHATSERVER_H

#include<Database.h>
#include<User.h>
#include<vector>
#include<string>
#include<sys/socet.h>
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
		if(socet != -1) {
			close(socet);
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
	void broadcat(const std::string& message, Client* exclude = nullptr);
	void removeClient(Client* client);
	void cleanup();

piblic:
	ChatServer(int p = 8080);
	~ChatServer();

	bool start();
	void stop();
};

#endif // CHATSERVER_H
