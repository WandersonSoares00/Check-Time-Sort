
PROJ_NAME = main
CXX = g++
CPPFLAGS = -Wall -Wextra -std=c++17 -pedantic -g
RM = rm -rf
OBJ_DIR = bin
RM = rm -rf

all: $(OBJ_DIR) $(PROJ_NAME)

$(PROJ_NAME):	$(OBJ_DIR)/main.o $(OBJ_DIR)/sort.o $(OBJ_DIR)/utill.o
	$(CXX) $(CPPFLAGS) $^ -o $(PROJ_NAME)

$(OBJ_DIR)/main.o:	src/main.cpp src/utill.hpp src/sort.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/utill.o: src/utill.cpp src/sort.hpp $(OBJ_DIR)/sort.o
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/sort.o: src/sort.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR) $(PROJ_NAME)

