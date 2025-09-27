CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude -fPIC

SRC_DIR = src
BUILD_DIR = build
LIB_DIR = libs

SHARIDE_LIB = libmath.so 
TARGET = app #fayli anun

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR)/$(TARGET)
	
$(BUILD_DIR)/$(TARGET) : $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) -shared -o $(LIB_DIR)/$(SHARIDE_LIB) $(filter-out $(BUILD_DIR)/main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) $(BUILD_DIR)/main.o -L$(LIB_DIR) -lmath -o $@
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  # $< nuyn dependencies => SRC_DIR
						# $@ nuyn target => BUILD_DIR

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)/$(SHARIDE_LIB)

rebuild: clean all
