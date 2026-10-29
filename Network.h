#pragma once
#include <string>

bool StartNetwork();
void StopNetwork();

bool ConnectToServer(const std::string& ip, int port, int& socketDescriptor);
bool SendMessageToServer(int socketDescriptor, const std::string& message);
bool ReceiveMessageFromServer(int socketDescriptor, std::string message);
void CloseConnection(int socketDescriptor);