
class Computer {

public:
	Computer();

	Computer(const Computer& copy);

	~Computer();

	void set_socket(SOCKET soc);

	SOCKET get_socket(void);

	
	void recieve_messages();

private:
	SOCKET socket;


};

