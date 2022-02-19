#include "server.h"

int run_client(void) {

	SOCKET sock;
	//SOCKET ListenSock;
	SOCKADDR_IN address;

	int addrsize = sizeof(address);

	long ok;
	char MESSAGE[200];

	WSAData WSD;
	WORD DllVersion;
	DllVersion = MAKEWORD(2, 1);
	ok = WSAStartup(DllVersion, &WSD);

	while (true) {
		sock = socket(AF_INET, SOCK_STREAM, NULL);

		address.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS); // ???
		address.sin_family = AF_INET;
		address.sin_port = htons(PORT);

		connect(sock, (SOCKADDR*)&address, sizeof(address));

		string msg;
		cout << "Enter message: ";
		cin >> msg;
		const char* s = msg.c_str();
		ok = send(sock, s, 1024, NULL);

		ok = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
		string reply;
		reply = MESSAGE;
		cout << "Server says: " << reply << endl;

	}

	

}

