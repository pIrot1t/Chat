#if defined(_WIN32) && !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x0600
#endif

#include "Network.h"

#ifdef _WIN32

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#else

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>

#endif

#include <iostream>
#include <cstring>

using namespace std;

bool StartNetwork()
{
#ifdef _WIN32
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		return false;
	}
#endif

	return true;
}

void StopNetwork()
{
#ifdef _WIN32
	WSACleanup();
#endif
}

bool ConnectToServer(const string& ip, int port, int& socketDescriptor)
{
#ifdef _WIN32
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
#else
	int sock = socket(AF_INET, SOCK_STREAM, 0);
#endif

	if (sock < 0)
	{
		return false;
	}

	sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);

	if (inet_pton(AF_INET, ip.c_str(), &serverAddress.sin_addr) != 1)
	{
#ifdef _WIN32
		closesocket(sock);
#else
		close(sock);
#endif
		return false;
	}

	if (connect(sock, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
	{
#ifdef _WIN32
		cout << "Connection failed. Error: " << WSAGetLastError() << endl;
		closesocket(sock);
#else
        cout << "Connection failed. Error: " << strerror(errno) << endl;
		close(sock);
#endif
		return false;
	}

	socketDescriptor = (int)sock;
	return true;
}

bool SendMessageToServer(int socketDescriptor, const string& message)
{
#ifdef _WIN32
	SOCKET sock = socketDescriptor;
#else
	int sock = socketDescriptor;
#endif

	int sent = 0;
	int total = (int)message.size();

	while (sent < total)
	{
		int result = send(sock, message.data() + sent, total - sent, 0);
		
		if (result <= 0)
		{
			return false;
		}

		sent += result;
	}

	return true;
}

bool ReceiveMessageFromServer(int socketDescriptor, string& message)
{
#ifdef _WIN32
	SOCKET sock = socketDescriptor;
#else
	int sock = socketDescriptor;
#endif

	char buffer[1024];
	int received = recv(sock, buffer, sizeof(buffer), 0);

	if (received <= 0)
	{
		return false;
	}

	message.assign(buffer, received);

	return true;
}

void CloseConnection(int socketDescriptor)
{
#ifdef _WIN32
	closesocket(socketDescriptor);
#else
	close(socketDescriptor);
#endif
}
