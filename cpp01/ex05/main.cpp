#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harl;

	if (argc != 2) {
		std::cerr << "use: ./<program> <level>\n" << std::endl;
		return (1);
	}
	harl.complain((std::string)argv[1]);
}
