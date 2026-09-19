#include "Client.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Client client;

  client.StartClient();

  client.SendMessage("Hello");

  client.GetMessage();

  client.StopClient();
}
