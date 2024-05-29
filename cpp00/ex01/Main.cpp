#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;

	std::cout << "Welcome, this is a crappy 80s style phonebook" << std::endl;
	InitInstructions();
	phonebook.size = 0;
	while (1)
	{
		if (phonebook.Command())
			break;
	}
	return (0);
}
