CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude -g 

SRC_DIR = src
BUILD_DIR = build
LIB_DIR = libs

#executable fayler
SERVER_TARGET = server
CLIENT_TARGET = client

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

#main fayler
SERVER_OBJS = $(BUILD_DIR)/main_server.o
CLIENT_OBJS = $(BUILD_DIR)/main_client.o

#mnacac objektner (database, user, message, ChatServer, ChatClient)
COMMON_OBJS = $(filter-out $(SERVER_OBJS) $(CLIENT_OBJS) $(OBJS))

all: $(SERVER_TARGET) $(CLIENT_TARGET)

#server
$(SERVER_TARGET): $(SERVER_OBJS) $(COMMON_OBJS)
	$(CXX)  -lsqlite3 -lpthread -o $@

#client
$(CLIENT_TARGET): $(CLIENT_OBJS) $(COMMON_OBJS)
	$(CXX) -lsqlite3 -lpthread -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

	
clean:
	rm -rf $(BUILD_DIR) $(SERVER_TARGET) $(CLIENT_TARGET) chat.db

rebuild: clean all

#DB stexcel => make db
db:
	./init_db.sh
