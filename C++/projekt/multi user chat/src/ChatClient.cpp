#include <../include/ChatClient.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <chrono>
#include <iomanip>
#include <sstream>

ChatClient::ChatClient(const std::string& host, int p, const std::string& name) :
	hostname(host),
	username(name),
	port(p) {}

ChatClient::~ChatClient() { disconnect(); }

bool ChatClient::connectToServer() {
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd < 0) {
		std::cerr << "error:  socet not create\n";
		return false;
	}

	hostent* server = gethostbyname(hostname.c_str());
	if(!server) {
		std::cerr << "error: can't found host \n";
		return false;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

	if(connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		std::cerr << "can't join server\n";
		return false;
	}

	std::string join = username + "log in chat";
	send(socket_fd, join.c_str(), join.size(), 0);

	running = true;
	startReceiving();
	return true;
}

void ChatClient::startReceiving() {
	receive_thread = std::thread(&ChatClient::receiveMessages, this);
}

void ChatClient::receiveMessages() {
	char buffer[2048];
	while(running) {
		memset(buffer, 0, sizeof(buffer));
		int bytes = recv(socket_fd, buffer, sizeof(buffer) - 1, 0);
		
		if(bytes <= 0) {
			if(running) {
				std::cerr << "\nnoconnect server\n";
			}
			break;
		}

		std::string msg(buffer);
		if(msg.find("log in chat") != std::string::npos) {
			std::cout << "-> " << msg << "\n";
		} else if(msg.find("log out chat") != std::string::npos) {
			std::cout << "<- " << msg << "\n";
		} else {
			auto now = std::chrono::system_clock::now();
			auto tt = std::chrono::system_clock::to_time_t(now);
			std::tm* local = std::localtime(&tt);

			char time_str[10];
			std::strftime(time_str, sizeof(time_str), "%H:%M", local);

			size_t colon = msg.find(':');
			if(colon != std::string::npos) {
				std::string sender = msg.substr(0, colon);
				std::string text = msg.substr(colon + 2);
				
				std::cout << "[" << time_str << "]" << sender << ":" << text << "\n";
				std::cout << ">" << std::flush;

			}
		}
	}
}

void ChatClient::start() {
	if(running && !receive_thread.joinable()) {
		receive_thread = std::thread(&ChatClient::receiveMessages, this);
	}
}

bool ChatClient::isConnected() const{
	return socket_fd != -1 && running;
}

bool ChatClient::sendMessage(const std::string& Message) {
	if(!isConnected() || Message.empty()) return false;
	
	std::string full = username + ": " + Message;
	int sent = send(socket_fd, full.c_str(), full.size(), 0);

	auto now = std::chrono::system_clock::now();
    auto tt = std::chrono::system_clock::to_time_t(now);
    std::tm* local = std::localtime(&tt);
    char time_str[10];
    std::strftime(time_str, sizeof(time_str), "%H:%M", local);

    std::cout << "[" << time_str << "] " << username << ": " << Message << "\n";
    std::cout << "> " << std::flush;

    return sent > 0;
}

void ChatClient::disconnect() {
    if (running) {
        running = false;

        if (socket_fd != -1) {
            std::string bye = username + " log out chat";
            send(socket_fd, bye.c_str(), bye.size(), 0);
            shutdown(socket_fd, SHUT_RDWR);
            close(socket_fd);
            socket_fd = -1;
        }

        if (receive_thread.joinable()) {
            receive_thread.join();
        }
    }
}
