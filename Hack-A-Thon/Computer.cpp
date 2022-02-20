#include "server.h"

Computer::Computer(SOCKET soc) {
	socket = soc;
}

Computer::Computer(const Computer& copy) {
	set_socket(copy.get_socket());
}

Computer::~Computer() {
	cout << "Comp obj was destroyed" << endl;
}

int Computer::set_socket(SOCKET soc) {
	return (socket = soc);
}

SOCKET Computer::get_socket(void) const{
	return socket;
}


void Computer::recieve_messages() {


}

void set_user_socket(Computer& client, SOCKET ListenSock, SOCKADDR_IN* address, int* addrsize) {

	int counter = 1;
	while (counter) {
		if (client.set_socket(accept(ListenSock, (SOCKADDR*)address, addrsize))) {
			counter = 0;
			cout << " Client Has been Set" << endl;
		}
	}


}

