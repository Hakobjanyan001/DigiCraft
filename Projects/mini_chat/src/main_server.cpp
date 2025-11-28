#include <../include/ChatServer.h> 
#include <iostream>
#include <csignal>

ChatServer* Server = nullptr;
void signalHandler(int signum);

int main() {
	ChatServer server(8080);
	Server = &server;
	signal(SIGINT, signalHandler);
	signal(SIGTERM, signalHandler);
	server.start();
	return 0;
}

void signalHandler(int signum) {
	std::cout << "server closed" << std::endl;
	if(Server) {
		Server->stop();
	}	   
	exit(signum);
}
