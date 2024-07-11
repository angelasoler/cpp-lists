
#include "Animal.hpp"

Animal::Animal(void)
{
	if (DEBUG)
		std::cout << "Animal constructor called" << std::endl;
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

std::string	Animal::getType() const
{
	return (this->type);
}

Animal::Animal(const Animal &copy)
{
	if (DEBUG)
		std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
	if (DEBUG)
		std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->setType(copy.getType());
	}
	return *this;
}

Animal::~Animal(void)
{
	if (DEBUG)
		std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "An animal sound" << std::endl;
}
