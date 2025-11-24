#include <../include/ChatServer.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <algorithm>

ChatServer::ChatServer(int p) : 
	server_socket(-1), port(p), running(false), db() {
		if(!db.open()) {
				std::cerr << "[Server] can not open DB" << std::endl;
		}
}

ChatServer::~ChatServer() {
	stop();
	cleanup();
}

bool ChatServer::start() {
	// creat socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket == -1) {
		std::cerr << "[Server] socket creation failed\n";
		return false;
	}
	
	// settings
	int opt = 1;
	setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	// to tie in port 
	sockaddr_in addr{};
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port); // port -> nework byte order
	
	if(bind(server_socket, (sockaddr*)&addr, sizeof(addr)) < 0) {
		std::cerr << "bind" << ")\n";
		close(server_socket);
		return false;
	}

	// listen
	if(listen(server_socket, 10) < 0) {
		std::cerr << "[Server] listen is falied (port "<< port << ")\n";
		close(server_socket);
		return false;	
	}
	
	std::cout << "[Server] is listen " << port << " on port\n";

	running = true;

	// start accepting thread
	std::thread accepter(&ChatServer::acceptClients, this);
	accepter.detach();

	return true;
}

void ChatServer::acceptClients() {
	while(running) {
		sockaddr_in client_addr{};
		socklen_t len = sizeof(client_addr);
		int client_sock = accept(server_socket, (sockaddr*)&client_addr, &len);

		if(!running) break;

		if(client_sock < 0) {
			if(errno == EINTR) continue;
			std::cerr << "[Server] accept failed\n";
			continue;
		}
		
		// creat Client
		Client* client = new Client(client_sock);
		client->user = User();
		client->authenticated = false;
		
		{
			std::lock_guard<std::mutex> lock(clients_mutex);
			clients.push_back(client);
		}

		std::cout << "[Server] new client` " << client_sock << "\n";

		// run handle thread
		client->thread = std::thread(&ChatServer::handleClient, this, client);
	}
}

void ChatServer::handleClient(Client* client) {
	char buffer[1024];
	std::string line;

	std::string welcome = "Hello! write your message:\n";
	send(client->socket, welcome.c_str(), welcome.size(), 0);

	while(running && client->socket != -1) {
					std::cout << "*****************************" << std::endl;
		// clean buffer
		memset(buffer, 0, sizeof(buffer));
		
		// write socket
		int bytes = read(client->socket, buffer, sizeof(buffer) - 1);
		std::cout << "Bytes Res: " << bytes << std::endl;
		if(bytes <= 0) {
			if(bytes == 0) break;
			if(errno == EINTR || errno == EAGAIN) continue;
			break;
		}

		buffer[bytes] = '\0';
		line += buffer;

		// Process complete lines
		size_t pos;
			std::cout << __FUNCTION__ << __LINE__ << std::endl;
			std::cout << "LINE::::: " << line << std::endl;
			//while((pos = line.find('\n')) != std::string::npos) {
			while(true) {
			std::cout << __FUNCTION__ << __LINE__ << std::endl;
				std::string msg = line.substr(0, pos);
				line.erase(0, pos + 1);
				
				//if client don't write name -> ask for write  name
				if(!client->authenticated) {
					std::string name = msg;
					std::cout << "IFFFFF*****************************" << msg<< std::endl;
				
					//clean spaces
					name.erase(std::remove(name.begin(), name.end(), '\r'), name.end());
					name.erase(std::remove(name.begin(), name.end(), '\n'), name.end());
					while(!name.empty() && std::isspace(static_cast<unsigned char> (name.back()))) {
						name.pop_back();
					}

					while(!name.empty() && std::isspace(static_cast<unsigned char> (name.front()))) {
						name.erase(0, 1);
					}

					// cheak unnown simvols
					if(name.find(':') != std::string::npos || name.find('\n') != std::string::npos) {
						send(client->socket, "name cannot contain ':' or '\n'", 50, 0);
								continue;
					}

					// chek length
					if(name.empty() || name.size() > 50) {
						send(client->socket, "Name must be 1-50 characters\n", 40, 0);
						continue;
					}
					
					// find or creat user
					User u = db.getUser(name);
					if(u.getId() == -1) {
							int new_id = db.addUser(name);
							u = User(new_id, name);
					}

					client->user = u;
					client->authenticated = true;

					std::string ok = "Hello" + name + "!\n";
					send(client->socket, ok.c_str(), ok.size(), 0);

					// sent last 10 messages
					auto last_msgs = db.getLastMessages(10);
					for(const auto& m : last_msgs) {
						std::string hist = "[" + m.username + "]: " + m.connected + "\n";
						send(client->socket, hist.c_str(), hist.size(), 0);
					}
				} else if(msg.compare(0, 4, "MSG:")) {  //already logged in -> procces MSG
					std::string text = msg.substr(4);
					std::cout << "IFF*****************************" << text << std::endl;
					
					// remove first spaces
					text.erase(0, text.find_first_not_of(" \t"));
					if(text.empty()) continue;

					// save on Db
					db.addMessage(client->user.getId(), text);
					

					// sent broadcast
					std::string formatted = "[" + client->user.getUsername() + "]: " + text;
					broadcast(formatted, client->socket);
				} else { // Unnown command
					send(client->socket, "write MSG:text\n", 30, 0);
				}
		}
	}
	removeClient(client);
}

void ChatServer::broadcast(const std::string& message, int  exclude_fd = -1) {
	std::string full_msg = message + "\n";
	std::lock_guard<std::mutex> lock(clients_mutex);
	for(Client* c : clients ) {
		if(c->socket == exclude_fd || c->socket == -1 || !c->authenticated) continue;
		send(c->socket, full_msg.c_str(), full_msg.size(), 0);
	}	
}

void ChatServer::removeClient(Client* client) {
	{
		std::lock_guard<std::mutex> lock(clients_mutex);
		clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
	}
	std::cout << "[Server] Client disconnected` " << client->socket << "\n";
	delete client;
	}

void ChatServer::stop() {
	running = false;
	if(server_socket != -1) {
		shutdown(server_socket, SHUT_RDWR);
		close(server_socket);
		server_socket = -1;
	}
}

void ChatServer::cleanup() {
	std::lock_guard<std::mutex> lock(clients_mutex);
	for(Client* c : clients) {
		delete c;
	}
	clients.clear();
}
