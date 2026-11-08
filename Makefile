SRC = main.cpp UserManager.cpp ChatManager.cpp MessageManager.cpp sha1.cpp Client.cpp Network.cpp
TARGET = Chat

Chat: $(SRC)
	g++ -static -static-libgcc -static-libstdc++ $(SRC) -o $(TARGET) -std=c++17 -lws2_32
	
