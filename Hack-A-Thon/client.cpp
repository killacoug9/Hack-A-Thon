#include "server.h"


int run_client(void) {

	// Init WINSOCK
	WSAData WSD;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &WSD) != 0) {
		cout << "Failed to initilize WINSOCK" << endl;
		return -1;
	}

	// Create Socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, NULL);
	if (sock < 0) {
		cout << "Failed to create socket" << endl;
		return -1;
	}
		
	// Define Server Info
	SOCKADDR_IN address;
	ZeroMemory(&address, sizeof(address));
	address.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS); //
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);

	int addrsize = sizeof(address);

	char MESSAGE[200];

	connect(sock, (SOCKADDR*)&address, sizeof(address));

	auto Recieve = [&sock, &MESSAGE]() {
		while (true) {
			if (recv(sock, MESSAGE, sizeof(MESSAGE), NULL) == 0) {
				ZeroMemory(MESSAGE, 200);
				string reply;
				reply = MESSAGE;
				cout << reply << endl;
			}
		}
	};

	auto Send = [&sock]() {
		while (true) {
			string msg;
			cout << "Enter message: ";
			getline(cin, msg);
			const char* s = msg.c_str();
			send(sock, s, 1024, NULL);
		}
	};

	thread s(Send);

	thread r(Recieve);

	s.join();

	r.join();
	

}

