
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	if (DEBUG)
		std::cout << "WrongAnimal constructor called" << std::endl;
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	if (DEBUG)
		std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (DEBUG)
		std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->setType(copy.getType());
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	if (DEBUG)
		std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "An WrongAnimal sound." << std::endl;
}
