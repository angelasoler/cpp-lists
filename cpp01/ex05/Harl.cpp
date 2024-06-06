#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[LEVELS])() = {&Harl::debug, &Harl::info,
	                                   &Harl::warning, &Harl::error};
	for (short i = 0; i < LEVELS; i++)
	{
		if (level == levels[i])
			return ((this->*funcPtr[i])());
	}
	std::cerr << "Error: Invalid level" << std::endl;
	std::cerr << "Try one of these:" << std::endl;
	for (short i = 0; i < LEVELS; i++)
		std::cerr << i + 1 << ") " << levels[i] << std::endl;
}
