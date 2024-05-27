#include "Phonebook.hpp"

void	InitInstructions(void)
{
	std::cout << std::endl;
	std::cout << "- There is just these 3 commands:";
	std::cout << std::endl;
	std::cout << " ADD" << std::endl;
	std::cout << " SEARCH" << std::endl;
	std::cout << " EXIT" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	Phonebook	phonebook;

	std::cout << "Welcome, this is a crappy 80s style phonebook" << std::endl;
	InitInstructions();
	while (1)
	{
		if (phonebook.Command())
			break;
	}
	return (0);
}
