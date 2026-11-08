SRC = main.cpp UserManager.cpp ChatManager.cpp MessageManager.cpp sha1.cpp Client.cpp Network.cpp
TARGET = Chat

Chat: $(SRC)
	g++ $(SRC) -o $(TARGET) -std=c++17
	
