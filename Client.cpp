#include "Client.h"
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>

bool Client::StartClient() {
  socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_file_descriptor == -1) {
    cout << "Creation of socket failed" << endl;
    return false;
  }

  serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serveraddress.sin_port = htons(PORT);
  serveraddress.sin_family = AF_INET;

  connection =
      connect(socket_file_descriptor, (struct sockaddr *)&serveraddress,
              sizeof(serveraddress));

  if (connection == -1) {
    cout << "Connection with the server failed" << endl;
    return false;
  }

  return true;
}

void Client::StopClient() {
  cout << "Client has been stopped" << endl;
  close(socket_file_descriptor);
}

char Client::GetMessage() {
  bzero(message, sizeof(message));
  read(socket_file_descriptor, message, sizeof(message));
  cout << message << endl;
  return *message;
}

void Client::SendMessage(char *_message) {
  strcpy(message, _message);
  bzero(message, sizeof(message));
  ssize_t bytes = write(socket_file_descriptor, message, sizeof(message));
  if (bytes >= 0) {
    cout << "Data successfully sent to the server" << endl;
  }
}
