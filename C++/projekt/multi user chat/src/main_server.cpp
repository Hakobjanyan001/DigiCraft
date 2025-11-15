#include <./include/ChatServer.h>
#include <iostream>
#include <csignal>

ChatServer* server = nullptr;

void signalHandler(int signum) {
		std::cout << "\n{Server} closed..." << signum << std::endl;
		if(server) {
				server->stop();
				delete server;
		}
		exir(signum);
}

int main() {
	signal(SIGINT, signalHandler);
	signal(SIGTERM, signalHandler);

	std::cout << "multi-user chat\n";
	std::cout << "connected localhost:8080" << std::endl;

	server = new ChatServer(8080);
	if(!server->start()) {
		std::cerr << "server noconnected" << std::endl;
		delete server
		return 1;
	}
	std::cout << "server is connected, for stop enter Ctrl+C" << std::endl;

	while(true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}
