#include "server.h"

int run_server() {

	SOCKET ConSock;
	SOCKET ListenSock;
	SOCKADDR_IN address;
	int addrsize = sizeof(address);

	long ok;
	char MESSAGE[200];

	WSAData WSD;
	WORD D11Version;
	D11Version = MAKEWORD(2, 1);
	ok = WSAStartup(D11Version, &WSD);

	ConSock = socket(AF_INET, SOCK_STREAM, NULL);

	address.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS); 
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);

	ListenSock = socket(AF_INET, SOCK_STREAM, NULL);
	bind(ListenSock, (SOCKADDR*)&address, sizeof(address));
	listen(ListenSock, MAX_USERS); // Was 

	cout << "Server waiting for conections";

	while (true) {
		if (ConSock = accept(ListenSock, (SOCKADDR*)&address, &addrsize)) { // he put = but should be == i think
			ok = recv(ConSock, MESSAGE, sizeof(MESSAGE), NULL);
			string msg;
			msg = MESSAGE;
			cout << "Client says: " << msg << endl;

			string reply;
			cout << "Enter reply: ";
			cin >> reply;
			const char* s = reply.c_str();
			ok = send(ConSock, s, 1024, NULL);


		}
	}

	return 0;
}