#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

#define MESSAGE_LENGTH 1024
#define PORT 51111

class Client {
private:
  int socket_file_descriptor, connection;
  struct sockaddr_in serveraddress, client;
  char message[MESSAGE_LENGTH];

public:
  bool StartClient();

  void StopClient();

  char GetMessage();

  void SendMessage(char *message);
};
