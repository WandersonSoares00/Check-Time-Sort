
PROJ_NAME = main
CXX = g++
CPPFLAGS = -Wall -Wextra -std=c++17 -pedantic
RM = rm -rf
OBJ_DIR = bin
RM = rm -rf

all: $(PROJ_NAME)

$(PROJ_NAME):	src/main.cpp
	$(CXX) $(CPPFLAGS) $^ -o $(PROJ_NAME)

clean:
	$(RM) $(PROJ_NAME)
