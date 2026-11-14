SRC = main.cpp UserManager.cpp ChatManager.cpp MessageManager.cpp sha1.cpp Client.cpp Network.cpp
TARGET = Chat

ifeq ($(OS),Windows_NT)
	LDFLAGS = -static -static-libgcc -static-libstdc++ -lws2_32
else
	LDFLAGS =
endif

$(TARGET): $(SRC)
	g++ $(SRC) -o $(TARGET) -std=c++17 $(LDFLAGS)
