#include "server.h"



int main() {
	// remeber that if you arent the server computer you have to set the IS_SERVER constant to 0;
	if (IS_SERVER) {
		run_server();
	}
	else {
		run_client();
	}

	//thread server_thread(run_server);

	//thread client_thread(run_client);




	return 0;
 }