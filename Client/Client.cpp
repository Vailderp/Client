#include <iostream>
#include <Client.h>

int main(int argc, char* argv[])
{
	Client client(1111, "192.168.0.105");
	
	client.onAny(
	[](const char* packet, SOCKET)
	{
		std::cout << packet << std::endl;
	});

	client.on("hello",
		[&](const char* packet, SOCKET)
		{
			std::cout << "How are you?" << std::endl;
			client.emit("I am good, and you?");
		});
	
	client.start();

	while (true)
	{
		
	}

	return EXIT_SUCCESS;
}