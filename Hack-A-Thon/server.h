#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define SCK_VERSION2 0x0202 // version 2
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <conio.h>
#include <stdio.h>

#include <WinSock2.h>
#include <Windows.h>
#include <sstream>
#include <string>

#include <thread>
//std::thread thread_object(callable);
#include "Computer.hpp"

#define SCK_VERSION 0x0202 // version 2

#define SERVER_IP_ADDRESS "10.219.207.40"
#define PORT 49417

#define MAX_USERS 5

#define IS_SERVER 1

using namespace std;

int run_server(void);

int run_client(void);

void set_user_socket(Computer& client, SOCKET ListenSock, SOCKADDR_IN& address, int& addrsize);
