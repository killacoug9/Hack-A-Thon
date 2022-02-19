#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define SCK_VERSION2 0x0202 // version 2

#pragma comment(lib, "ws2_32.lib");
#include <iostream>
#include <conio.h>
#include <stdio.h>

#include <WinSock2.h>
#include <Windows.h>
#include <sstream>
#include <string>

#include <thread>

#define SCK_VERSION 0x0202 // version 2

#define PORT 80;

using namespace std;

int run_server(void);

int run_client(void);
