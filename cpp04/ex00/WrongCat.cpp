
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	setType("WrongCat");
	if (DEBUG)
		std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	if (DEBUG)
		std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}
