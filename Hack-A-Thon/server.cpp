#include "server.h"

int run_server() {

	// Init WINSOCK
	WSAData WSD;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &WSD) != 0) {
		cout << "Server failed to init WINSOCK" << endl;
		return -1;
	}

	//// Creates the sockets for connecting and listing 


	Computer client1(socket(AF_INET, SOCK_STREAM, NULL), 1);

	Computer client2(socket(AF_INET, SOCK_STREAM, NULL), 2);

	SOCKET ListenSock = socket(AF_INET, SOCK_STREAM, NULL);
	if (ListenSock < 0) {
		cout << "Failed to create Listen socket" << endl;
		return -1;
	}

	//SOCKET person_two_soc = socket(AF_INET, SOCK_STREAM, NULL);


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


	//thread t1(set_user_socket, (client1, ListenSock, &address, &addrsize));

	//thread t2(set_user_socket, client2, ListenSock, &address, &addrsize);

	auto f = [&client1, ListenSock, address, &addrsize]() {
		int counter = 1;
		while (counter) {
			if (client1.set_socket(accept(ListenSock, (SOCKADDR*)&address, &addrsize))) {
				counter = 0;
				cout << " Client Has been Set" << endl;
			}
		}
	};


	thread t1(f);

	auto f2 = [&client2, ListenSock, address, &addrsize]() {
		int counter = 1;
		while (counter) {
			if (client2.set_socket(accept(ListenSock, (SOCKADDR*)&address, &addrsize))) {
				counter = 0;
				cout << " Client Has been Set" << endl;
			}
		}
	};
	thread t2(f2);

	t1.join();
	t2.join();
	

	// multi threadign out of while loop?? use a recieve func??

	
	auto c1Recieve = [&client1, &MESSAGE, &client2]() {
		while (true) {
			recv(client1.get_socket(), MESSAGE, sizeof(MESSAGE), NULL);
			string client_input_msg;
			client_input_msg = MESSAGE;
			cout << "User "  << client1.get_number() << " says:" << client_input_msg << endl;


			const char* s = client_input_msg.c_str();
			send(client2.get_socket(), s, 1024, NULL);
		}
	};


	auto c2Recieve = [&client2, &MESSAGE, &client1]() {
		while (true) {
			ZeroMemory(MESSAGE, 200);
			recv(client2.get_socket(), MESSAGE, sizeof(MESSAGE), NULL);
			string msg;
			msg = MESSAGE;
			cout << "User " << client2.get_number() << " says:" << msg << endl;

			const char* s = msg.c_str();
			send(client1.get_socket(), s, 1024, NULL);
		}
	};

	thread t3(c1Recieve);
	thread t4(c1Recieve);

	t3.join();
	t4.join();


	return 0;
}