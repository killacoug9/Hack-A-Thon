#include "server.h"



int main() {

	thread server_thread(run_server);

	thread client_thread(run_client);




	return 0;
 }