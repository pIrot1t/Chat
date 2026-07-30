SRC = main.cpp UserManager.cpp ChatManager.cpp Chat.cpp sha1.cpp
TARGET = chat
PREFIX = /usr/local/bin

chat:	$(SRC)
	g++ $(SRC) -o $(TARGET)

install:
	sudo install $(TARGET) $(PREFIX)

uninstall:
	sudo rm -rf $(PREFIX)/$(TARGET)
