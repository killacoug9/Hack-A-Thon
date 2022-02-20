
class Computer {

public:
	Computer(SOCKET soc, int n);

	Computer(const Computer& copy);

	~Computer();

	int set_socket(SOCKET soc);

	SOCKET get_socket(void) const;

	void recieve_messages();

	int get_number(void);

private:
	SOCKET socket;
	int number;

};

