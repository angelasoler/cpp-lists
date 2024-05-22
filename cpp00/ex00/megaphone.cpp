#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "SCREAAAAAM" << std::endl;
		return (1);
	}
	for (int nwords = 1; nwords < argc; nwords++)
	{
		for (int i = 0; argv[nwords][i]; i++)
			std::cout << (char)std::toupper(argv[nwords][i]);
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
