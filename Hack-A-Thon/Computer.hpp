
class Computer {

public:
	Computer(SOCKET soc);

	Computer(const Computer& copy);

	~Computer();

	int set_socket(SOCKET soc);

	SOCKET get_socket(void) const;

	void recieve_messages();

private:
	SOCKET socket;


};

