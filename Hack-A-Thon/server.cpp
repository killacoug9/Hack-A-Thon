#include "server.h"

int run_server() {

	// Init WINSOCK
	WSAData WSD;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &WSD) != 0) {
		cout << "Server failed to init WINSOCK" << endl;
		return -1;
	}
	

	// Creates the sockets for connecting and listing 
	SOCKET ConSock = socket(AF_INET, SOCK_STREAM, NULL);;
	SOCKET ListenSock = socket(AF_INET, SOCK_STREAM, NULL);;
	SOCKADDR_IN address;

	int addrsize = sizeof(address);


	// Defines Server Info
	address.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS); 
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);


	//ListenSock = socket(AF_INET, SOCK_STREAM, NULL);
	bind(ListenSock, (SOCKADDR*)&address, sizeof(address));
	listen(ListenSock, MAX_USERS); 


	char MESSAGE[200];

	int person_one_ID;

	cout << "Server waiting for conections" << endl;

	while (true) {
		if (ConSock = accept(ListenSock, (SOCKADDR*)&address, &addrsize)) { // he put = but should be == i think
			recv(ConSock, MESSAGE, sizeof(MESSAGE), NULL);
			string msg;
			msg = MESSAGE;
			cout << "Client says: " << msg << endl;

			string reply;
			cout << "Enter reply: ";
			cin >> reply;
			const char* s = reply.c_str();
			cout << "the ConSock print: " << ConSock << endl;
			send(ConSock, s, 1024, NULL);


		}
	}

	return 0;
}