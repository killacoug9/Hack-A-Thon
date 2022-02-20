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
	SOCKET person_one_soc = socket(AF_INET, SOCK_STREAM, NULL);
	if (person_one_soc < 0) {
		cout << "Failed to create person one socket" << endl;
		return -1;
	}
	SOCKET ListenSock = socket(AF_INET, SOCK_STREAM, NULL);
	if (ListenSock < 0) {
		cout << "Failed to create Listen socket" << endl;
		return -1;
	}
	SOCKET person_two_soc = socket(AF_INET, SOCK_STREAM, NULL);
	if (person_two_soc < 0) {
		cout << "Failed to create person 2 socket" << endl;
		return -1;
	}

	SOCKADDR_IN address;

	int addrsize = sizeof(address);


	// Defines Server Info
	address.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS); 
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);


	
	bind(ListenSock, (SOCKADDR*)&address, sizeof(address)); // 
	listen(ListenSock, MAX_USERS);


	char MESSAGE[200];

	

	cout << "Server waiting for conections" << endl;

	// listing socket is our socket, the socket for server. ConSoc is the clients socket. so we send to ConSoc



	while (true) {


		// we would have multi threading here to recieve both sockets at same time
		if (person_one_soc = accept(ListenSock, (SOCKADDR*)&address, &addrsize)) { // he put = but should be == i think
			recv(person_one_soc, MESSAGE, sizeof(MESSAGE), NULL);
			string msg;
			msg = MESSAGE;
			cout << "Client says: " << msg << endl;

			string reply;
			cout << "Enter reply: ";
			cin >> reply;
			const char* s = reply.c_str();
			send(person_one_soc, s, 1024, NULL);


		}
	}

	return 0;
}