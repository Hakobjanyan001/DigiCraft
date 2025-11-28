CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude -g 

SRC_DIR = src
BUILD_DIR = build

SERVER_TARGET = server
CLIENT_TARGET = client


SERVER_SRC = $(SRC_DIR)/main_server.cpp $(SRC_DIR)/ChatServer.cpp $(SRC_DIR)/Database.cpp
CLIENT_SRC = $(SRC_DIR)/main_client.cpp $(SRC_DIR)/ChatClient.cpp

SERVER_OBJS = $(SERVER_SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
CLIENT_OBJS = $(CLIENT_SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: $(SERVER_TARGET) $(CLIENT_TARGET)

$(SERVER_TARGET): $(SERVER_OBJS) 
	$(CXX) $(SERVER_OBJS) -lsqlite3 -o $@

$(CLIENT_TARGET): $(CLIENT_OBJS) 
	$(CXX) $(CLIENT_OBJS) -lsqlite3 -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(SERVER_TARGET) $(CLIENT_TARGET) chat.db

rebuild: clean all
 
 
